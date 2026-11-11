#include <bits/stdc++.h>
using namespace std;
vector<int> G[17];
int n,k;
int ans=114514;
int vis[17],vis1[17],maxn[17],b1,b2;
void dfs1(int u)
{
	vis1[u]=1;
	for(int v:G[u])
	{
		if(!vis1[v]&&vis[v]) dfs1(v);
	}
	return;
}
int check()
{
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=vis[i],vis1[i]=0;
	if(cnt!=k) return 0;
	cnt=0;
	b1=b2=-1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			if(!vis1[i]) dfs1(i),cnt++;
			if(cnt==1) b1=i;
			else b2=i;
			if(cnt>2) return 0;
		}
	}
	return 1;
}
void dfs2(int u,int st)
{
	vis1[u]=1;
	maxn[u]=min(maxn[u],st);
	for(int v:G[u])
	{
		if(vis1[v]) continue;
		if(vis[v]&&st) continue;
		if(vis[v]) dfs2(v,0);
		else dfs2(v,st+1);
	}
	return;
}
int calc()
{
	for(int i=1;i<=n;i++) vis1[i]=0,maxn[i]=1e5;
	dfs2(b1,0);
	for(int i=1;i<=n;i++) vis1[i]=0;
	if(b2!=-1) dfs2(b2,0);
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,maxn[i]);
	return res;
}
void dfs(int k)
{
	if(k==n+1)
	{
		if(check())
		{
			ans=min(ans,calc());
		}
		return;
	}
	vis[k]=1;
	dfs(k+1);
	vis[k]=0;
	dfs(k+1);
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans=114514;
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
