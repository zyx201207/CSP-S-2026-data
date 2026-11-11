#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,k,ans=1e18;
vector<int> G[105];
bool vis[105],vis2[105];
int a[105];
void bfs(int st)
{
	queue<int> q;q.push(st);
	while(q.size())
	{
		int t=q.front();q.pop();
		vis2[t]=1;
		for(int v:G[t])
			if(vis[v] && vis2[v]==0)q.push(v);
	}
}
bool check()
{
	int sum=0;memset(vis2,0,sizeof vis2);
	for(int i=1;i<=n;i++)
		if(vis2[i]==0 && vis[i])bfs(i),sum++;
	if(sum>2)return 0;
	return 1;
}
int bfs2(int st)
{
	memset(vis2,0,sizeof vis2);
	queue<int> q,w;q.push(st);w.push(0);
	while(q.size())
	{
		int t=q.front(),tw=w.front();q.pop(),w.pop();
		vis2[t]=1;
		for(int v:G[t])
		{
			if(vis2[v])continue;
			if(vis[v])return tw+1;
			q.push(v);w.push(tw+1);
		}
	}
}
int cnt()
{
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		maxx=max(maxx,bfs2(i));
	}return maxx;
}
void dfs(int id)
{
	if(id==k+1)
	{
		if(check())ans=min(ans,cnt());
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		a[id]=i;
		vis[i]=1;
		dfs(id+1);
		vis[i]=0;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;ans=1e18;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}dfs(1);cout<<ans<<"\n";
	}
	return 0;
}
