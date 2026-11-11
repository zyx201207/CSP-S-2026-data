#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int N=505,M=5e5+5;
const long long inf=1e18;
int c,n,m,d,q;
long long w[M];
long long dp[N][N];
vector<pair<int,long long> > t[M];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dp[i][k]==inf) continue;
			for(int j=1;j<=n;j++){
				if(dp[k][j]==inf) continue;
				if(dp[i][k]+dp[k][j]<dp[i][j]) dp[i][j]=dp[i][k]+dp[k][j];
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=inf;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int u; cin >> u;
			long long w; cin >> w;
			t[u].push_back({i,w});
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=0;i<t[k].size()-1;i++){
			for(int j=i+1;j<t[k].size();j++){
				int u=t[k][i].first;
				int v=t[k][j].first;
				long long w=t[k][i].second+t[k][j].second;
				dp[u][v]=min(dp[u][v],w);
				dp[v][u]=min(dp[v][u],w);
			}
		}
	}
	floyd();
	while(q--){
		int s,e;
		cin >> s >> e;
		long long ans=inf;
		for(int i=0;i<t[s].size();i++){
			for(int j=0;j<t[e].size();j++){
				ans=min(ans,t[s][i].second+t[e][j].second+dp[t[s][i].first][t[e][j].first]);
			}
		}
		cout << w[s]+ans+w[e] << '\n';
	}
	return 0;
} 
