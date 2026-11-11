#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+10;
int n,ans;
ll a[N],m,b[N];
bool check(int x,int idx){
	ll t = a[idx]*x;
	if(b[idx-1]-b[idx-x-1]+m<t)return 1;
	else return 0;
}
int BS(int maxn){
	int l = -1,r = maxn;
	while(l+1<r){
		int mid = (l+r)>>1;
		if(check(mid,maxn)){
			r = mid;
		}else{
			l = mid;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i] = a[i];
		b[i] += b[i-1];
	}
	for(int i=1;i<=n;i++){
		int t = BS(i)+1;
		ans = max(ans,t);
	}
	cout << ans;
	return 0;
}
//就走到这里，失望的人
//这次没能红了眼眶
