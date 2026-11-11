#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
int c, d, n, m, q, x, y, id[5005][5005], t[5005][5005], a[5005][5005], ans, k[MAXN], w[MAXN];
vector<int> g[MAXN];
void dfs(int u, int l, int sum)
{
	if (u == y)
	{
		ans = min(ans, sum + t[l][id[l][u]]);
		return;
	}
	for (int v : g[u])
	{
		if (l == v) 
		{
			dfs(a[l][id[l][u] + 1], l, sum);
		}
		else dfs(a[v][id[v][u] + 1], v, sum + t[l][id[l][u]] + t[v][id[v][u]]);
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			g[a[i][j]].push_back(i);
			id[i][a[i][j]] = j;
		}
	}
	while (q--)
	{
		ans = 0x3f3f3f3f;
		cin >> x >> y;
		for (int p : g[x])
		{
			dfs(x, p, t[p][id[p][x]] + w[x]);
		}
		cout << ans + w[y] << '\n';
	}
	return 0;
}

