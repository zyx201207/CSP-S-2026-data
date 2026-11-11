#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t;
void solve(){
	int n; ll d,ans=0; cin>>n>>d;
	vector<ll> x(n+1);
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		vector<int> dp(n+1,INT_MAX),way(n+1);
		way[i]=1,dp[i]=0;
		for(int j=i+1;j<=n;j++){
			for(int k=j-1;k>=i&&x[j]-x[k]<=d;k--){
				if(dp[k]+1<dp[j]) dp[j]=dp[k]+1,way[j]=way[k];
				else if(dp[k]+1==dp[j]) way[j]+=way[k];
			}
			if(way[j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
