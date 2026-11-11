#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;
const int N = 1010000;
vector<int> e[N];
int n, k, fa[N];
bool v[N];

int find(int u) {
	if (u == fa[u]) return u;
	return fa[u] = find(fa[u]);
}

void dfs(int u, int fa, int d, int S, int &dis) {
	if (S & (1 << (u - 1))) dis = min(dis, d);
	for (auto v : e[u])
		if (v != fa) dfs(v, u, d + 1, S, dis);
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans = inf;
	for (int S = 0; S < (1 << n); S++) {
		if (__builtin_popcount(S) != k) continue;
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int u = 0; u < n; u++) if (S & (1 << u)) {
			for (auto v : e[u + 1]) if (S & (1 << (v - 1))) {
				fa[find(u + 1)] = find(v);
			}
		}
		int cc = 0;
		for (int i = 1; i <= n; i++) if (S & (1 << (i - 1))) {
			cc += fa[i] == i;
		}
		if (cc > 2) continue;
		int ma = 0;
		for (int r = 0; r < n; r++) if (!(S & (1 << r))) {
			int dis = inf;
			dfs(r + 1, 0, 0, S, dis);
			ma = max(ma, dis);
		}
		ans = min(ans, ma);
	}
	printf("%d\n", ans);
}

int tp, tc;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &tp, &tc);
	for (int T = 0; T < tc; T++) {
		solve();
	}
	return 0;
}
