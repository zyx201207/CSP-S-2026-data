#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,INF=1e18;
int c,t,n,k,dp[N][N],f[N][N],father[N],dis[3][N];
bool vis[3][N];
vector<int> e[N];
void dfs(int u,int fa) {
	father[u]=fa;
	for (int v:e[u]) {
		if (v==fa) continue;
		dfs(v,u);
		for (int j=0;j<=k;j++) {
			for (int x=0;x<=j;x++) {
				f[u][j]=max(dp[u][j-x],dp[v][x]+1);
			}
		}
		for (int j=0;j<=k;j++) dp[u][j]=f[u][j];
	}
}
int solve(int x,int y) {
	vis[1][x]=vis[2][y]=vis[2][x]=vis[1][y]=1;
	queue<pair<int,int> > q;
	if (vis[1][father[x]]==0) {
		q.push({father[x],1});
		dis[1][father[x]]=1;
	}
	while (!q.empty()) {
		int u=q.front().first,cnt=q.front().second;
		q.pop();
		for (int v:e[u]) {
			if (vis[1][v]) continue;
			q.push({v,cnt+1});
			vis[1][v]=1;
			dis[1][v]=cnt+1;
		}
	}
	if (vis[2][father[y]]==0) {
		q.push({father[y],1});
		dis[2][father[y]]=1;
	}
	while (!q.empty()) {
		int u=q.front().first,cnt=q.front().second;
		q.pop();
		for (int v:e[u]) {
			if (vis[2][v]) continue;
			q.push({v,cnt+1});
			vis[2][v]=1;
			dis[2][v]=cnt+1;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (dis[1][i]!=INF && dis[2][i]!=INF) ans=max(ans,min(dis[1][i],dis[2][i]));
		else if (dis[1][i]!=INF) ans=max(ans,dis[1][i]);
		else ans=max(ans,dis[2][i]);
	}
	for (int i=1;i<=n;i++) vis[1][i]=vis[2][i]=0,dis[1][i]=dis[2][i]=INF;
	return ans;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while (t--) {
		cin>>n>>k;
		for (int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		int ans=INF;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				int s=solve(i,j);
				for (int x=1;x<=k;x++) s=max(s,max(dp[i][x],dp[j][k-x]));
				ans=min(ans,s);
			}
		}
		cout<<ans<<"\n";
		for (int i=1;i<=n;i++) {
			father[i]=0;
			e[i].clear();
			for (int j=0;j<=k;j++) dp[i][j]=f[i][j]=0;
		}
	}
	return 0;
}
