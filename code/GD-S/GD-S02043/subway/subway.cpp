#include<bits/stdc++.h>
#define int long long
#define pii pair <int, int>
#define fi first
#define se second
using namespace std;

const int M = 5e5 + 1000;

int c, n, m, d, q, w[M], dis[M], g[M][25], dep[M];
bool vis[M];

vector <pii> f[M];

void dfs(int u, int fa)
{
	vis[u] = true;
	g[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for (auto x : f[u])
	{
		int v = x.fi, ww = x.se;
		if (v == fa || vis[v]) continue;
		vis[v] = true;
		dis[v] = dis[u] + ww;
		dfs(v, u);
	}
}

int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--) if (dep[g[x][i]] >= dep[y]) x = g[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) if (g[x][i] != g[y][i]) x = g[x][i], y = g[y][i];
	return g[x][0];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		tot++;
		for (int j = 1; j <= k; j++)
		{
			int x, tim;
			cin >> x >> tim;
			f[x].push_back({m + tot, tim});
			f[m + tot].push_back({x, tim});
		}
	}
	dfs(1, 0);
	for (int j = 1; j <= 20; j++) for (int i = 1; i <= m + tot; i++) g[i][j] = g[g[i][j - 1]][j - 1];
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		int faa = lca(u, v);
		cout << w[u] + w[v] + dis[u] + dis[v] - 2 * dis[faa] << '\n';
	}
	return 0;
}
