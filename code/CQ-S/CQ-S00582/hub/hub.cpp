#include <bits/stdc++.h>
//#define int long long int
using namespace std;

const int MAXN = 1e5 + 5;
int n, k, ans = MAXN, dp[MAXN][25], dep[MAXN];
vector<int> g[MAXN];

void ycl(int x, int fa) {
	dp[x][0] = fa, dep[x] = dep[fa] + 1;
	for (int i = 1; i <= 20; i++) dp[x][i] = dp[dp[x][i - 1]][i - 1];
	for (auto y : g[x]) {
		if (y == fa) continue;
		ycl(y, x);
	}
}

int get_lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int j = 20; j >= 0; j--) if (dep[dp[x][j]] >= dep[y]) x = dp[x][j];
	if (x == y) return x;
	for (int j = 20; j >= 0; j--) if (dp[x][j] != dp[y][j]) x = dp[x][j], y = dp[y][j];
	return dp[x][0]; 
}

int check(int x, int fa, int s) {
	int tot = 0, cnt = 0;
	for (auto y : g[x]) {
		if (y == fa) continue;
		tot += check(y, x, s);
		cnt += ((s >> y) & 1);
	}
	if (cnt == 0 && ((s >> x) & 1)) tot ++;
	return tot;
}

int get_dis(int x, int y) {
	int lca = get_lca(x, y);
	return dep[x] + dep[y] - 2 * dep[lca]; 
}

int get(int s) {
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		int t = MAXN;
		for (int j = 1; j <= n; j++) {
			if (((s >> j) & 1) == 0) continue;
			t = min(t, get_dis(i, j));
		}
		tot = max(tot, t);
	}
	return tot;
}

void dfs(int x, int s, int cnt) {
	if (x == n + 1) {
		if (cnt != k) return;
		if (check(1, 0, s) <= 2) ans = min(ans, get(s));
		return;
	}
	dfs(x + 1, s, cnt);
	dfs(x + 1, s | (1 << x), cnt + 1);
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= n - 1; i++) {
		int x, y; cin>> x >> y;
		g[x].push_back(y), g[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) for (int j = 0; j <= 20; j++) dp[i][j] = 0;
	ans = MAXN;
	ycl(1, 0);
	dfs(1, 0, 0);
	cout << ans << '\n'; 
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int op, T; cin >> op >> T; while (T--) solve();
	return 0;
}

