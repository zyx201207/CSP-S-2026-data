#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+12;
ll n,m;
ll a[N],ps[N];
void init(){
	sort(a+1,a+n+1);
	ps[0]=0;
	for(ll i=1;i<=n;++i){
		ps[i]=ps[i-1]+a[i];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	//cin>>n>>m;
	for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
	init(); 
	ll ans=0;
	for(ll l=1,r=1;r<=n;++r){
		const ll len=r-l+1;
		if(1ll*len*a[r]-(ps[r]-ps[l-1])<=m)ans=max(ans,len);
		else if(l<r)++l;
	}
	printf("%lld",ans);
	return 0;
} 
