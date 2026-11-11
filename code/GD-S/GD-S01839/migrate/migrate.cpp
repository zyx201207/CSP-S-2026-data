#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int dp[maxn][maxn],ans[maxn][maxn];
bool vis[maxn];
vector<int> g[maxn];
int n;
void dfs(int u){
	vis[u]=1;
	for(int v:g[u]){
		dp[u][v]=1;
		if(vis[v])continue;
		for(int i=1;i<=n;i++){
			if(dp[i][u]!=0)dp[i][v]=min(dp[i][v],dp[i][u]+1);
		}
		dfs(v);
	}
}
void dfs(int u){
	vis[u]=1;
	for(int v:g[u]){
		dp[u][v]=1;
		if(vis[v])continue;
		for(int i=1;i<=n;i++){
			if(dp[i][u]!=0)dp[i][v]=min(dp[i][v],dp[i][u]+1);
		}
		dfs(v);
	}
}
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]!=dp[j][i]){
				if(dp[i][j]==0x3f3f3f3f)dp[i][j]=dp[j][1];
				else dp[j][i]=d[i][j];
			}
		}
	}
	
}
