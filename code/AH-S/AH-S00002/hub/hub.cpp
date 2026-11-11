#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> g[1000005];
int c,T,k,f[1000005],vis[1000005],dis[1000005],n;
void bfs(int u)
{
	queue<int> q;
	q.push(u);
	vis[u]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int v:g[t]){
			if(f[v]&&!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
}
int ltk()
{
	int S=0;
	for(int i=1;i<=n;i++)S+=f[i];
	if(S!=k)return 0;
	for (int i = 1;i <= n;i++) vis[i] = 0;
	int s=0;
	for (int i = 1;i <= n;i++)
	{
		if(f[i]&&!vis[i])bfs(i),s++;
	}
	return (s<=2);
}
void bfs2()
{
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(f[i])q.push(i),dis[i]=0;
	}
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int v:g[t]){
			if(dis[v]==-1){
				dis[v]=dis[t]+1;
				q.push(v);
			}
		}
	}
}
int calc(){
	for (int i = 1;i <= n;i++)dis[i]=-1;
	bfs2();
	int ma=-1;
	for(int i=1;i<=n;i++) ma=max(ma,dis[i]);
	return ma;
}
int ans=INT_MAX;
void dfs(int u){
	if(u==n+1)
	{
		if(ltk())ans=min(ans,calc());
		return;
	}
	f[u]=1;
	dfs(u+1);
	f[u]=0;
	dfs(u+1);
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)f[i]=0;
	for(int i=1;i<=n;i++)g[i].clear();
	ans=INT_MAX;

	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
