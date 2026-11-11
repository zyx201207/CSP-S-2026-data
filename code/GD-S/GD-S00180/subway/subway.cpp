#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int tim[N];
long long dp[505][505];
int G[505][N];
vector<int>vis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,0x3f,sizeof(dp));
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>tim[i];
	}
	for (int i=1;i<=n;i++){
		dp[i][i]=0;
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			G[i][u]=v;
			vis[u].push_back(i);
		}
	}
	for (int i=1;i<=m;i++){
		for (auto j:vis[i]){
			for (auto k:vis[i]){
				if (j!=k&&dp[j][k]>G[j][i]+G[k][i])dp[j][k]=G[j][i]+G[k][i];
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int k=1;k<=n;k++){
			for (int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);		
			}
		}
	}
	while (q--){
		long long x,y,ans=1e18;
		cin>>x>>y;
		for (auto i:vis[x]){
			for (auto j:vis[y]){
				ans=min(ans,dp[i][j]+G[i][x]+G[j][y]+tim[x]+tim[y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
