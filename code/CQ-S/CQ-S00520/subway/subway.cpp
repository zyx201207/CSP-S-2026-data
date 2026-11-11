#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
int c, n, m, d, q, w[500010], k[510], a[500010], t[500010], dis[2000010];
vector<pair<int, int> > e[2000010];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
bool vis[2000010];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		e[i].push_back({(2 * n + 1) * m + i, w[i]});
		e[(2 * n + 1) * m + i].push_back({i, w[i]});
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];
			e[(2 * n + 1) * m + a[j]].push_back({i * m + a[j], 0});
			e[i * m + a[j]].push_back({(2 * n + 1) * m + a[j], 0});
			e[i * m + a[j]].push_back({(n + i) * m + a[j], t[j]});
			e[(n + i) * m + a[j]].push_back({i * m + a[j], t[j]});
		}
		for (int j = 1; j < k[i]; j++) {
			e[(n + i) * m + a[j]].push_back({(n + i) * m + a[j + 1], 0});
			e[(n + i) * m + a[j + 1]].push_back({(n + i) * m + a[j], 0});
		}
	}
	int M = m * (2 * n + 2);
	while (q--) {
		int x, y;
		cin >> x >> y;
		for (int i = 0; i <= M; i++) vis[i] = false, dis[i] = inf;
		dis[x] = 0;
		pq.push({0, x});
		while (pq.size()) {
			int u = pq.top().second;
			pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
			for (auto i : e[u]) {
				int v = i.first, ww = i.second;
				if (dis[u] + ww < dis[v])
					dis[v] = dis[u] + ww, pq.push({dis[v], v});
			}
		}
		cout << dis[y] << '\n';
	}
	return 0;
}
