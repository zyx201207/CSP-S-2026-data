#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],s[500010];
ll ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(ll k=1;k<=n;k++){
		ll l=k,r=n;
		while(l<r){
			ll md=(l+r-1)/2;
			ll sl=md-k,lj=s[md-1]-s[k-1];
			if(m<(sl*a[md]-lj)) r=md-1;
			 else if(m>(sl*a[md]-lj))l=md+1;
			  else{
			  	l=r=md;
			  	break;
			  }
		}
		if((r-k+1)>ans){
			ans=r-k+1;
		}
	}
	printf("%lld",ans);
}
