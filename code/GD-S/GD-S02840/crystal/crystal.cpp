#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,ans;
ll a[N],pre[N];
inline bool chk(ll tgt){
	ll mn=2e18;
	for(ll i=tgt;i<=n;i++)mn=min(mn,tgt*a[i]-(pre[i]-pre[i-tgt]));
	return mn<=m;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	ll l=0,r=n+1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid;
	}printf("%lld",ans);
	return 0;
}

