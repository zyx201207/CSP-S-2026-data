#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=5e5+5, Minn=1e12+5;
ll n, m, a[N], sum[N];
bool check(ll k){
	// 来滑动一个窗口长度为m，那么我们就可以来寻找长度为m的总和；
	for(int i=k; i<=n; i++){
		//取当前大小
		ll now=a[i];
		now*=k;
		ll num=sum[i]-sum[i-k];
		if((now-num)<= m && now>=num) return true;
		
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll l=0, r=n+1;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i) sum[i]=sum[i-1] + a[i];
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid)) {l=mid;}
		else r=mid-1;
	}
	cout<< l;
	return 0;
}

