#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
const int maxn = 501000;
vector<pair<int,int> > G[maxn], Q[maxn];
int c, n, m, d, q, W[maxn], ans[maxn], X[maxn], Y[maxn], dis[maxn], vis[maxn];
int read()
{
	int res = 0;
	char c = getchar();
	while(c<'0' || c>'9')
		c = getchar();
	while(c>='0' && c<='9')
	{
		res = res*10+c-'0';
		c = getchar();
	}
	return res;
}
void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void dij(int st)
{
	for(int i=1;i<=m+n;i++)
		dis[i] = INF, vis[i] = 0;
	dis[st] = 0;
	priority_queue<pair<int,int> > pq;
	pq.push({0,st});
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i=0;i<(int)(G[u].size());i++)
		{
			int v = G[u][i].first, w = G[u][i].second;
			if(dis[v]>dis[u]+w)
			{
				dis[v] = dis[u]+w;
				pq.push({-dis[v],v});
			}
		}
	}
	for(int i=0;i<(int)(G[st].size());i++)
	{
		int u = G[st][i].first, w = G[st][i].second;
		for(int j=0;j<(int)(Q[u].size());j++)
		{
			int v = Q[u][j].first, idx = Q[u][j].second;
			ans[idx] = min(ans[idx], dis[v]+w);
		}
	}
}
void bfs(int st)
{
	for(int i=1;i<=m+n;i++)
		dis[i] = INF, vis[i] = 0;
	queue<int> qu;
	qu.push(st);
	dis[st] = 0;
	vis[st] = 1;
	while(!qu.empty())
	{
		int u = qu.front();
		qu.pop();
		for(int i=0;i<(int)(G[u].size());i++)
		{
			int v = G[u][i].first;
			if(!vis[v])
			{
				vis[v] = 1;
				qu.push(v);
				dis[v] = dis[u]+1;
			}
		}
	}
	for(int i=0;i<(int)(G[st].size());i++)
	{
		int u = G[st][i].first, w = G[st][i].second;
		for(int j=0;j<(int)(Q[u].size());j++)
		{
			int v = Q[u][j].first, idx = Q[u][j].second;
			ans[idx] = min(ans[idx], dis[v]+w);
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)
		W[i] = read();
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u, v = m+i, w;
			u = read();
			w = read();
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans[i] = INF;
		X[i] = read();Y[i] = read();
		Q[X[i]].push_back({Y[i],i});
		Q[Y[i]].push_back({X[i],i});
	}
	for(int i=1;i<=n;i++)
	{
		if(c>=12 && c<=19)
			bfs(i+m);
		else
			dij(i+m);
	}
	for(int i=1;i<=q;i++)
	{
		write(ans[i]+W[X[i]]+W[Y[i]]);
		puts("");
	}
	return 0;
}
