#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,k;
vector<int>g[N];
int b[N],vis[N],dis[N];
void ddfs(int u)
{
	vis[u]=1;
	for(int v:g[u])
	{
		if(!vis[v]&&b[v])
		{
			ddfs(v);
		}
	}
}
void jfs(int u)
{
	for(int v:g[u])
	{
		if(dis[v]>dis[u]+1)
		{
			dis[v]=dis[u]+1;
			jfs(v);
		}
	}
}
int R=1e9;
void dfs(int x,int s)
{
	if(s>k)return;
	if(x==n+1)
	{
		if(s!=k)return;
		for(int i=1;i<=n;++i)vis[i]=0,dis[i]=n;
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
//			if(b[i])cout<<i<<" ";
			if(b[i])dis[i]=0;
			if(b[i]&&!vis[i])
			{
				ddfs(i);
				++cnt;
				if(cnt>2)return;
			}
		}
//		cout<<"\n";
		for(int i=1;i<=n;++i)
		{
			if(b[i])
			{
				jfs(i);
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			ans=max(ans,dis[i]);
		}
		R=min(R,ans);
		return;
	}
	b[x]=1;
	dfs(x+1,s+1);
	b[x]=0;
	dfs(x+1,s);
}
inline void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1;i<n;++i)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	R=1e9;
	dfs(1,0);
	cout<<R<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0),cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--)solve();
}
