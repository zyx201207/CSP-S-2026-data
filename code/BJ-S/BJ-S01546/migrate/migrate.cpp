#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ll cnt=0;
				for(ll k=i+1;k<j;k++){
					if(x[k]-x[i]<=d&&x[j]-x[k]<=d){
						cnt++;
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}