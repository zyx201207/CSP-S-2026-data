#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = 1e6 + 505;
int c, n, m, d, q;
int d1[N], de[N], rt = 1, f[N][21];
vector<pii> e[N];
int lca(int x, int y) {
	if (de[x] < de[y]) swap(x, y);
	for (int i = 0; i <= 20; ++i) {
		if (de[x] == de[y]) break;
		x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; --i) {
		if (x != y) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
void dfs(int u, int fa) {
	for (auto [v, w] : e[u]) {
		if (v == fa) continue;
		f[v][0] = u;
		de[v] = de[u] + 1;
		d1[v] = d1[u] + w;
		dfs(v, u);
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; ++i) {
		int w; cin >> w;
		e[n + 2 * i + 1].push_back({n + i * 2 + 2, w});
		e[n + 2 * i + 2].push_back({n + i * 2 + 1, w});
	}
	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		for (int j = 0; j < k; ++j) {
			int a, t; cin >> a >> t;
			e[i + 1].push_back({n + 2 * a, t});
			e[n + 2 * a].push_back({i + 1, t});
		}
	}
	dfs(rt, 0);
	for (int i = 1; i <= n + 2 * m; ++i) {
		for (int j = 1; j <= 20; ++j) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	while (q--) {
		int p1, p2; cin >> p1 >> p2;
		p1 = n + p1 * 2 - 1;
		p2 = n + p2 * 2 - 1;
		int LCA = lca(p1, p2);
		cout << d1[p1] + d1[p2] - 2 * d1[LCA] << "\n";
	}
	return 0;
}