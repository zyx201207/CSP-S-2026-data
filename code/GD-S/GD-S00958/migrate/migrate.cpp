#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll t,c;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<ll>v(n+1),la(n+1);
		ll cnt=1;
		for(ll i = 1; i <= n; i ++){
			cin>>v[i];
			while(v[i]-v[cnt]>d)cnt++;
			la[i]=cnt;
		}
		ll ans=0;
		for(ll i = 1; i <= n; i ++){
			vector<ll>dis(n+1),dp(n+1);
			dp[i]=1;
			vector<ll>l(n+1),r(n+1);
			r[0]=i;
			l[0]=i;
			for(ll j = i+1; j <= n; j ++){
				dis[j]=dis[la[j]]+1;
				if(l[dis[j]]==0)l[dis[j]]=j;
				r[dis[j]]=j;
				dp[j]=dp[r[dis[j]-1]]-dp[la[j]-1];
//				cout<<r[dis[j]-1]<<' '<<la[j]-1<<"  ";
				if(dp[j]==2)ans++;
//				cout<<dp[j]<<' ';
				dp[j]+=dp[j-1];
				
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}

