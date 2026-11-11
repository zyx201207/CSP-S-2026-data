#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e16;
int c,n,m,d,q,w[500005],dis[505][505];
struct edge{
	int v,w;
};
vector<edge> g[500005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		while(k--)
		{
			int u,w;
			cin >> u >> w;
			g[u].push_back({i,w});
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) dis[i][j] = 0;
			else dis[i][j] = inf;
		}
	}
	for(int u = 1; u <= m; u++)
	{
		int l = g[u].size();
		for(int i = 0; i < l; i++)
		{
			for(int j = 0; j < l; j++)
			{
				int v1 = g[u][i].v,w1 = g[u][i].w,v2 = g[u][j].v,w2 = g[u][j].w;
				dis[v1][v2] = min(dis[v1][v2],w1+w2);
				dis[v2][v1] = min(dis[v2][v1],w1+w2);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				dis[j][k] = min(dis[j][k],dis[j][i] + dis[i][k]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		int lx = g[x].size(),ly = g[y].size(),ans = inf;
		for(int i = 0; i < lx; i++)
		{
			for(int j = 0; j < ly; j++)
			{
				int v1 = g[x][i].v,w1 = g[x][i].w,v2 = g[y][j].v,w2 = g[y][j].w;
				ans = min(ans,dis[v1][v2]+w1+w2+w[x]+w[y]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
