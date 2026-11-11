#include<bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX / 3;
int c, n, m, d, q, k, w[500005], a[505][500005], t[505][500005];
vector<pair<int, int> > g1[505], g2[500005], gg[505];
int main() {
#ifndef DPSLT_XWX
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	cin.tie(0) -> sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int u = 1; u <= n; ++u) {
		cin >> k;
		for (int j = 1, v, w; j <= k; ++j) cin >> v >> w, g1[u].emplace_back(v, w), g2[v].emplace_back(u, w);
	}
	for (int u = 1; u <= n; ++u)
		for (auto& [sv, w1] : g1[u])
			for (auto& [v, w2] : g2[sv]) {
				if (u == v) continue;
				gg[u].emplace_back(v, w1 + w2);
			}
	while (q--) {
		int x, y; long long ans = INF; queue<int> q;
		cin >> x >> y;
		for (auto& [begin, wb] : g2[x]) for (auto& [end, we] : g2[y]) {
			vector<long long> res(505, INF);
			q.push(begin); res[begin] = 0;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == end) continue;
				for (auto& [v, w] : gg[u]) {
					if (res[v] <= res[u] + w || ans <= res[u] + w) continue;
					res[v] = res[u] + w;
					q.push(v);
				}
			}
			ans = min(ans, res[end] + wb + we + w[x] + w[y]);
		}
		cout << ans << '\n';
	}
	return 0;
}
