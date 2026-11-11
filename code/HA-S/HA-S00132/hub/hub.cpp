#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int c, T;
const int N = 500;
int n, k;
vector<int> g[N];
vector<int> nodes;
vector<int> red, blue;

bool check() {
	for (int i = 0; i < red.size(); i ++) {
		int u = red[i];
		for (int j = i + 1; j < red.size(); j ++) {
			int v = red[j];
			if (u == v) continue;
			if (lower_bound(g[u].begin(), g[u].end(), v) == g[u].end()) {

				return false;
			}

		}
	}
	for (int i = 0; i < blue.size(); i ++) {
		int u = blue[i];
		for (int j = i + 1; j < blue.size(); j ++) {
			int v = blue[j];
			if (u == v) continue;
			if (lower_bound(g[u].begin(), g[u].end(), v) == g[u].end()) {

				return false;
			}

		}
	}
	return true;
}

int dep[N], fa[N][11];
void dfs(int u, int f) {
	dep[u] = dep[f] + 1;
	fa[u][0] = f;
	for (auto v : g[u]) {
		if (v == f) continue;
		dfs(v, u);

	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 10; i >= 0; i --) {
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 10; i >= 0; i --) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) g[i].clear();
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= 10; i ++) {
		for (int j = 1; j <= n; j ++) {
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
		}
	}
	for (int i = 1; i <= n; i ++) sort(g[i].begin(), g[i].end());
	int ans = 1e9;
	for (int msk = 0; msk < (1 << n); msk ++) { // which nodes are selected

		if (__builtin_popcount(msk) !=  k) continue;
		nodes.clear();
		for (int j = 0; j < n; j ++) {
			if (msk >> j & 1) nodes.push_back(j + 1);
		}
		int l = nodes.size();
		for (int m = 0; m < (1 << l); m ++) { // red or blue

			red.clear();
			blue.clear();
			for (int j = 0; j < l; j ++) {
				if (m >> j & 1) red.push_back(nodes[j]);
				else blue.push_back((nodes[j]));
			}
			if (!check() || (blue.size() == 0 || red.size() == 0)) continue;
//			for (auto k : red) cout << k << " ";
//			cout << "\n";
//			for (auto k : blue) cout << k << " ";
//			cout << "\n\n";
			int t = 1;
			for (int i = 1; i <= n; i ++) {
				if (1 << (i - 1) & msk) continue;
				int tx = 1e9;
				for (auto j : nodes) {
					if (i == j) continue;
					int d = dep[i] + dep[j] - 2 * dep[lca(i, j)];
//					if (blue[0] == 2 && blue[1] == 3 && red[0] == 10) {
//						cout << "!\n";
//						cout << i << " " << j << " " << d << "\n";
//					}
					tx = min(d, tx);
				}
				
				t = max(tx, t);
//				if (blue[0] == 2 && blue[1] == 3 && red[0] == 10) {
//					cout << "!" << tx << " " << t << "\n";
//				}
			}

//			cout << "#" << t<<"\n";
			ans = min(ans, t);
		}

	}
	cout << ans << "\n";
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	cin >> c >> T;
	while (T --) solve();
	return 0;
}

