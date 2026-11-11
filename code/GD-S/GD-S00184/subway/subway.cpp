#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 1e6 + 5, M = 505;

int c, n, m, d, q, idx;
array<ll, N> w;
array<int, N> qx, qy;
array<array<ll, M>, M> ds;

/*inline void solve1()
{
	for (int i = 1; i <= m; i++) cin >> w[i];
	idx = m;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int x, y;
			cin >> x >> y;
			idx++;
			G[idx].emplace_back(x, y);
			G[x].emplace_back(idx, y);
			if (j != 1)
			{
				G[idx - 1].emplace_back(idx, 0);
				G[idx].emplace_back(idx - 1, 0);
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		qx[i] = x, qy[i] = y;
		qry[x].emplace_back(i);
	}
	for (int i = 1; i <= m; i++)
	{
		if (qry[i].empty()) continue;
		for (int j = 1; j <= idx; j++) dist[j] = (ll)1e18;
		priority_queue<pair<ll, int>> pq;
		pq.emplace(0, i);
		dist[i] = 0;
		while (pq.size())
		{
			auto [d, u] = pq.top();
			pq.pop();
			d = -d;
			if (dist[u] != d) continue;
			for (auto &[j, w] : G[u])
			{
				if (dist[j] > dist[u] + w)
				{
					dist[j] = dist[u] + w;
					pq.emplace(-dist[j], j);
				}
			}
		}
		for (auto &id : qry[i])
		{
			ans[id] = dist[qy[id]] + w[qx[id]] + w[qy[id]];
		}
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}*/

array<vector<pair<int, int>>, N> vt;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < M; i++) ds[i].fill((ll)1e18), ds[i][i] = 0;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int x = 1; x <= k; x++)
		{
			int c, w;
			cin >> c >> w;
			vt[c].emplace_back(i, w);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (auto &[x, w1] : vt[i])
		{
			for (auto &[y, w2] : vt[i])
			{
				ds[x][y] = ds[y][x] = min(ds[x][y], 1ll * w1 + w2);
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
			}
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		ll ans = (ll)1e18;
		for (auto &[aa, a] : vt[x])
		{
			for (auto &[bb, b] : vt[y])
			{
				ans = min(ans, ds[aa][bb] + a + b);
			}
		}
		ans += w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
}
