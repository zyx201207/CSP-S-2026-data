#include<bits/stdc++.h>
using namespace std;
long long Test;
long long n,m,p,q;
long long stw[500050];
long long dp[550][550];
vector<pair<long long,long long> > sta[500050];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>Test;
	cin>>n>>m>>p>>q;
	for (long long i = 1;i <= m;i++){
		cin>>stw[i];
	}
	long long x,y,z;
	for (long long i = 1;i <= n;i++){
		cin>>x;
		for (long long j = 1;j <= x;j++){
			cin>>y>>z;
			sta[y].push_back({i,z});
		}
	}
	for (long long i = 1;i <= n;i++){
		for (long long j = 1;j <= n;j++){
			dp[i][j] = 1e18;
		}
		dp[i][i] = 0;
	}
	for (long long i = 1;i <= m;i++){
		for (auto u:sta[i]){
			for (auto v:sta[i]){
				if (u.first == v.first){
					continue;
				}
				dp[u.first][v.first] = dp[v.first][u.first] = min(dp[u.first][v.first],u.second+v.second);
			}
		}
	}
	for (long long k = 1;k <= n;k++){
		for (long long i = 1;i <= n;i++){
			for (long long j = 1;j <= n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for (long long i = 1;i <= q;i++){
		cin>>x>>y;
		long long ans = 1e18;
		for (auto u:sta[x]){
			for (auto v:sta[y]){
				ans = min(ans,dp[u.first][v.first]+stw[x]+stw[y]+u.second+v.second);
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
}
/*

*/
