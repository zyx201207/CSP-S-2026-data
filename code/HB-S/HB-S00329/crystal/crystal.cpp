#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],sum[500005];
bool check(ll mid){
	ll ans=1LL<<60;
	for(ll i=1;i+mid-1<=n;++i){
		ans=min(ans,a[i+mid-1]*mid-(sum[i+mid-1]-sum[i-1]));
	}
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
