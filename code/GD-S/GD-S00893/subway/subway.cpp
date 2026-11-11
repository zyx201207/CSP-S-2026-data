#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v, w;
};

int c, n, m, d, q;
int w[500005];
vector<edge> G[500005];
long long dis[505][505];

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			int a, t;
			cin >> a >> t;
			G[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1;i <= n;i++) dis[i][i] = 0;
	for (int i = 1;i <= m;i++)
	{
		for (int j = 0;j < G[i].size();j++)
		{
			for (int k = j + 1;k < G[i].size();k++)
			{
				dis[G[i][j].v][G[i][k].v] = min(dis[G[i][j].v][G[i][k].v], (long long)G[i][j].w + G[i][k].w);
				dis[G[i][k].v][G[i][j].v] = dis[G[i][j].v][G[i][k].v];
			}
		}
	}
	for (int k = 1;k <= n;k++)
	{
		for (int j = 1;j <= n;j++)
		{
			for (int i = 1;i <= n;i++)
			{
				dis[i][j] = min(dis[i][j], (long long)dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 1;i <= q;i++)
	{
		int u, v;
		cin >> u >> v;
		long long mn = 3e18;
		for (int j = 0;j < G[u].size();j++)
		{
			for (int k = 0;k < G[v].size();k++)
			{
				mn = min(mn, G[u][j].w + G[v][k].w + dis[G[u][j].v][G[v][k].v]);
			}
		}
		cout << (mn + w[u] + w[v]) << "\n";
	}
	return 0;
}
