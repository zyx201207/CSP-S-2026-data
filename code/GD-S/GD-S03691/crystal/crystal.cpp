#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5,INF=9e18;
ll n,m;
ll a[N+5],sum[N+5];
ll ans;
ll calc(ll x,ll pos){
	ll l=1,r=pos,s=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		ll S=sum[pos]-sum[mid-1];
		ll cst=(pos-mid+1)*x-S;
		if(cst<=m){
			r=mid-1;
			s=pos-mid+1;
		}
		else l=mid+1;
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		if(i!=n && a[i]==a[i+1]) continue;
		ans=max(ans,calc(a[i],i));
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
