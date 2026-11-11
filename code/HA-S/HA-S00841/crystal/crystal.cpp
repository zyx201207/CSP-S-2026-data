#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5*1e5+10;
int n,m,p1 = 1,p2 = 1,ans = INT_MIN;
ll a[N],b[N],c[N] = {0},t;
bool cmp(ll x,ll y){
	return x<y;
}

ll cal(int l,int r){//计算区间[l,r]的代价 
	return c[r] - ((a[r] - a[l-1]) * (l-1) + c[l - 1]); 
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 2;i<=n;i++){
		b[i] = a[i]-a[i-1];//差 
	}
	for(int i = 2;i<=n;i++){
		c[i] = b[i] * (i-1) + c[i-1];//1-n 的操作次数 
	}
	while(p1 <= p2 && p2 <= n){
		t = cal(p1,p2);
		if(t == m) {ans = max(ans,(p2 - p1 + 1)),p2++;}
		else if(t < m) {p2++;ans = max(ans,(p2 - p1));}
		else {p1++;}
	}
	cout<<ans;
}
