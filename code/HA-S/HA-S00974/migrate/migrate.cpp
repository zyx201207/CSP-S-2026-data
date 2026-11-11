#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll n,d;
		scanf("%lld%lld",&n,&d);
		ll x[n+5];
		for(ll i=1;i<=n;i++)scanf("%lld",&x[i]);
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+3;j<=n;j++){
				ll cnt=0;
				if(x[j]-x[i]<=d)continue;
				for(ll k=1;k<=n;k++){
					if(x[k]-x[i]<=d&&x[j]-x[k]<=d)cnt++;
				}
				if(cnt==0)continue;
				if(cnt==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}