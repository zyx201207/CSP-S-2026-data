#include <bits/stdc++.h>
using namespace std;
const long long N = 105, inf = 1e18;
long long c, t, n, m, u, v, f[N][N], b[N], fa[N], res, tmp, ans = inf;
vector<int> e[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void dfs(int x, int lst) {
	if (x > m) {
//		if (t == 0) cout << lst << '\n';
		bool bz = ((b[1] == 1) && (b[2] == 2) && b[3] == 3);
		for (int i = 1; i <= m; i++) fa[b[i]] = b[i];
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				if (f[b[i]][b[j]] == 1)
					fa[find(b[i])] = find(b[j]);
		unordered_set<int> st;
		for (int i = 1; i <= m && st.size() < 3; i++) st.insert(find(b[i]));
		if (st.size() > 2) return;
//		if (bz) cout << "!:" << st.size() << '\n';
		tmp = 0;
		for (int i = 1; i <= m; i++) {
			res = inf;
			for (int j = 1; j <= m; j++) if (j != i) res = min(res, f[b[i]][b[j]]);
			tmp = max(tmp, res);
		}
//		if (!t && tmp == 1) {
//			cout << "!:\n";
//			for (int i = 1; i <= m; i++) cout << i << ' ';
//			cout << '\n';
//		}
		ans = min(ans, tmp);
		return;
	}
	for (int i = lst + 1; i <= n; i++) {
		b[x] = i;
		dfs(x + 1, i);
	}
}
void sol() {
	ans = inf;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = f[j][i] = inf;
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		f[u][v] = f[v][u] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	dfs(1, 0);
	cout << ans << '\n';
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) sol();
	return 0;
} 
