#include <bits/stdc++.h>
#define ll long long
#define rd read()
using namespace std;
inline int read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
const int N = 5e5 + 5, M = 505;
int c, n, m, D, q, vis[N];
ll d[M][M], w[N], tmp[N];
vector<int> t[N];
unordered_map<int, int> mp[M];
vector<array<int, 2>> p[N];
vector<array<ll, 2>> g[N];
struct Node {
	int u; ll d;
	inline bool operator<(const Node &o) const {return d > o.d;} 
};
inline void dij(int s) {
	priority_queue<Node> q; 
	for (int i = 1; i <= n; ++i) d[s][i] = 1e18, vis[i] = 0;
	d[s][s] = 0, q.push({s, 0});
	while (!q.empty()) {
		int u = q.top().u; q.pop();
		if (vis[u]) continue ; vis[u] = 1;
		for (auto [v, w] : g[u])
			if (d[s][v] > d[s][u] + w) d[s][v] = d[s][u] + w, q.push({v, d[s][v]});
	}
}
signed main() {
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout); 
	c = rd, n = rd, m = rd, D = rd, q = rd;
	for (int i = 1; i <= m; ++i) w[i] = rd;
	for (int i = 1, k; i <= n; ++i) {
		k = rd; ll w;
		for (int j = 1, x; j <= k; ++j) {
			x = rd, w = rd; mp[i][x] = w;
			p[i].push_back({x, w}), t[x].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) tmp[j] = 1e18;
		for (auto [j, w] : p[i]) tmp[j] = w;
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue ;
			ll mn = 1e18;
			for (auto [k, w] : p[j])
				mn = min(mn, w + tmp[k]);
			g[i].push_back({j, mn});
		}
	}
	for (int i = 1; i <= n; ++i) dij(i);
	while (q--) {
		int x = rd, y = rd; ll ans = 1e18;
		for (int i : t[x]) for (int j : t[y]) ans = min(ans, d[i][j] + mp[i][x] + mp[j][y]);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
