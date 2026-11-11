#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 505, M = 5e5 + 10;

int c, n, m, d, q, w[M];
vector<pair<int, int>> g[M + N];
int dis[M + N];

void dij(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	q.push({0, s});
	while (q.size())
	{
		int u = q.top().second, d = q.top().first; q.pop();
		if (dis[u] != d) continue;
		for (auto e : g[u])
		{
			int v = e.first, w = e.second;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1, k; i <= n; ++i)
	{
		cin >> k;
		for (int j = 1, a, t; j <= k; ++j)
		{
			cin >> a >> t;
			g[a].push_back({i + m, t});
			g[i + m].push_back({a, t});
		}
	}
	for (int x, y; q; q--)
	{
		cin >> x >> y;
		dij(x);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

