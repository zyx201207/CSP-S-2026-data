#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
typedef pair<int, ll> PII;
typedef pair<ll, int> PLL;

const int N = 1e6 + 10;

int n, k;

namespace sol1 {
	const int LG = 20;
	vector<int> G[N];
	int dep[N], anc[N][LG], d[N];
	void dfs(int u, int fa) {
		anc[u][0] = fa;
		for (int i = 1; i < LG; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
		for (auto v : G[u]) {
			if (v != fa) {
				dep[v] = dep[u] + 1;
				dfs(v, u);
			}
		}
	}
	int lca(int u, int v) {
		if (u == v)return u;
		if (dep[u] < dep[v]) swap(u, v);
		int dt = dep[u] - dep[v];
		for (int i = LG - 1; ~i; i--) {
			if (dt >> i & 1) {
				u = anc[u][i];
			}
		}
		if (u == v) return u;
		for (int i = LG - 1; ~i; i--) {
			if (anc[u][i] != anc[v][i]) {
				u = anc[u][i];
				v = anc[v][i];
			}
		}
		return anc[u][0];
	}
	int dis(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}
	bool vis[N];
	void dfs1(int u, int fa, int S) {
		vis[u] = 1;
		for (auto v : G[u]) {
			if (v != fa) {
				if (S >> (v - 1) & 1) {
					dfs1(v, u, S);
				}
			}
		}
	}
	void sol() {
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].pb(v);
			G[v].pb(u);
		}
		for (int i = 1; i <= n; i++) {
			dep[i] = 0;
			for (int j = 0; j < LG; j++) {
				anc[i][j] = 0;
			}
		}
		dfs(1, 0);

		int answer = 1 << 30;
		for (int S = 0; S < (1 << n); S++) {
			if (__builtin_popcount(S) == k) {
//				for (int i = 0; i < n; i++) {
//					if (S >>i & 1){
//						cout << i << ' ';
//					}
//				}
//					cout << "\n===aaa===\n";
				int cnt = 0;
				for (int i = 1; i <= n; i++) vis[i] = 0;
				for (int i = 0; i < n; i++) {
					if (S >> i & 1) {
						if (!vis[i + 1]) {
							dfs1(i + 1, 0, S);
							++cnt;
						}
					}
				}
				if (cnt > 2) continue;
				for (int i = 1; i <= n; i++) {
					d[i] = 0;
				}
				int ans = 0;
				for (int i = 1; i <= n; i++) {
					if (S >> (i - 1) & 1) {
						d[i] = 0;
						continue;
					}
					int res = 1 << 30;
					for (int j = 0; j < n; j++) {
						if (S >> j & 1) {
							res = min(res, dis(i, j + 1));
						}
					}
					d[i] = res;
				}
				for (int i = 1; i <= n; i++) {
					ans = max(ans, d[i]);
				}
				answer = min(answer, ans);
//				cout << ans << "\n====bbbbb====\n";
			}
		}
		cout << answer << "\n";
 	}
}

void solve() {
	cin >> n >> k;
	if (n <= 10) {
		sol1::sol();
		return;
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
//
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int c, T;
	cin >> c >> T;
	while (T--) solve();

	return 0;
}

/*10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
