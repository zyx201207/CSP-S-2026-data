#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;

int c, t, n, k;
int fa[maxn][20], dep[maxn];

vector<int> e[maxn];

void dfs_lca(int x, int f) {
	dep[x] = dep[f] + 1;
	fa[x][0] = f;
	for (int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (int n_ex = e[x].size(), i = 0; i < n_ex; i++) {
		int v = e[x][i];
		if (v == f) continue;
		dfs_lca(v, x);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

void init() {
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 20; j++) fa[i][j] = 0;
		dep[i] = 0;
	}
}

void solve() {
	cin >> n >> k;	
	for (int i = 1, u, v; i <= n - 1; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs_lca(1, 0);
	int ans = INT_MAX;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int tmp = 0;
			for (int i = 1; i <= n; i++) {
				int dis = min(dep[i] + dep[x] - 2 * dep[lca(i, x)], dep[i] + dep[y] - 2 * dep[lca(i, y)]);
				if (i == x || i == y) dis = 0;
				tmp = max(tmp, dis);
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
