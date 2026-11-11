#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
using pli = pair<i64, int>;
constexpr int N = 2e5 + 5, mod = 998244353;
/*
做出来了！

注意到站台没用缩成一个点，等价于有一个 500 个特殊点，m 个站厅的图。

x-y 可以拆为先 x 走到某个特殊点，然后走到 y 的一个特殊点最后到 y

所以预处理任意两个特殊点的最短路，然后暴力枚举 x, y 的邻点即可。

我就说 d <= 20 是有用的 
*/
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	for (int i = 1; i <= m; i++) cin >> w[i];
	vector<vector<pii>> g(m + 1);
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		while (k--)
		{
			int x, y;
			cin >> x >> y;  
			g[x].push_back({i, y});
		}
	}
	vector<vector<i64>> dis(n + 1, vector<i64>(n + 1, 1e18));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			for (int k = j + 1; k < g[i].size(); k++)
			{
				int u = g[i][j].first, v = g[i][k].first, w = g[i][j].second + g[i][k].second;
				dis[u][v] = dis[v][u] = min(dis[u][v], w * 1ll);
			}
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		i64 ans = 1e18;
		for (auto it1 : g[x])
		{
			int i = it1.first, di = it1.second;
			for (auto it2 : g[y])
			{
				int j = it2.first, dj = it2.second;
				ans = min(ans, di + dj + dis[i][j]);
			}
		}
		cout << ans + w[x] + w[y] << "\n"; 
	}
	return 0;
}
