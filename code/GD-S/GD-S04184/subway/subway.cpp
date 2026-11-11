// 0

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kM = 1e6 + 7;

struct V {
	int dis, id;
	friend operator < (V x, V y) {
		return x.dis > y.dis;
	}
};

vector<pair<int, int> > g[kM];
int c, n, m, d, q, w[kM], a[kM], t[kM], k[kM], ans;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];
			g[a[j]].push_back({a[j] + i * n, t[j]});
			g[a[j] + i * n].push_back({a[j], t[j]});
			if (j > 1) {
				g[a[j]].push_back({a[j - 1], 0});
				g[a[j - 1]].push_back({a[j], 0});
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		ans = 0;
		vector<int> dis(n * 10 + 2, 2e18 + 7);
		vector<int> vis(n * 10 + 2, 0);
		int x, y;
		cin >> x >> y;
		ans += w[x] + w[y];
		priority_queue<V> q;
		q.push({0, x});
		dis[x] = 0;
		while (!q.empty()) {
			V t = q.top(); q.pop();
			int u = t.id;
			if (vis[u]) continue;
			vis[u] = 1;
			for (auto v : g[u]) {
				int to = v.first, ww = v.second;
				if (dis[to] > dis[u] + ww) {
					dis[to] = dis[u] + ww;
					q.push({dis[to], to});
				}
			}
		}
		cout << dis[y] + ans << "\n";
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


*/
