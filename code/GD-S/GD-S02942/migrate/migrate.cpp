#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+10;
ll a[N],dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++) dp[i]=1;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=d;j++){
				dp[i]=max(dp[i-1],dp[i-j]+1);
			}
		}
		
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ans=max(ans,dp[i]);
		}
		
		cout<<ans-1<<'\n';
	}
	return 0;
} 
