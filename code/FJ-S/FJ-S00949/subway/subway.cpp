#include <iostream>
#include <vector>
using namespace std;
struct edge{
	int u, v, w;
} e[500005];
int c, n, m, d, q;
int w[500005], k[505];
long long ans;
long long dep[1005];
int up[1005][25];

void dfs(int u, int fa)
{
	dep[u] = dep[fa] + e[u].w;
	up[u][0] = fa;
	for (int i = 1; i <= 20; i++)
	{
		up[u][i] = up[up[u][i-1]][i-1];
	}
	for (auto i : e)
	{
		int v = i.v;
		if (v == fa) continue;
		dfs(v, u);
	}
}

int lca(int u, int v)
{
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--)
	{
		if (dep[u]-(1<<i)>=dep[v])
			u = up[u][i];
	}
	if (u == v) return u;
	for (int i = 20; i >= 0; i--)
	{
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	}
	return up[u][0];
}

long long dist(int u, int v)
{
	return dep[u] + dep[v] - 2*dep[lca(u, v)];
}

int dfs1(int u, int v, int fa)
{
	int dist = 1e9;
	for (auto i : e)
	{
		int v = i.v, w = i.w;
		if (v == fa) continue;
		dist = min(dist, dfs());
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	if (c >= 7 && c <= 11)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> k[i];
			if (k[i] == 2)
			{
				int u, v, t1, t2;
				cin >> u >> t1 >> v >> t2;
				e[u] = {v, t1+t2};
				e[v] = {u, t1+t2};
			}
		}
		cout << dist(1, 2);
	}
	
	return 0;
}
