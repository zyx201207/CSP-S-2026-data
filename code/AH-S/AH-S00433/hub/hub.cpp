#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
constexpr int N = 1e6 + 10, INF = 1e9;
int C, T, n, k, r, low[N], deep[N], cnt;
bool f[N];
vector<int> g[N];
/*void dfs(const int u, const int fa);
void meow(const int u, const int fa, const int blk, const bool fill);
bool check(const int tmp) {
	r = tmp;
	cnt = 0;
	rep(i, 1, n) {
		f[i] = false;
	}
	dfs(1, 0);
	if (cnt > k) {
		return false;
	}
	meow(1, 0, 2, false);
	return cnt <= k;
}
void dfs(const int u, const int fa) {
	low[u] = INF;
	deep[u] = 0;
	bool has_son = false;
	for (const auto v : g[u]) {
		if (v != fa) {
			has_son = true;
			dfs(v, u);
			low[u] = min(low[u], low[v] + 1);
			deep[u] = max(deep[u], deep[v] + 1);
		}
	}
	if (!has_son) {
		low[u] = 0;
	}
	if (low[u] + deep[u] - 1 > r) {
		f[u] = true;
		low[u] = deep[u] = 0;
		++ cnt;
	}
}
void meow(const int u, const int fa, const int blk, const bool fill) {
	if (fill && f[u] == false) {
		f[u] = true;
		++ cnt;
	}
	int cc = 0;
	for (const auto v : g[u]) {
		if (v == fa || low[v] == INF) {
			continue;
		}
		++ cc;
	}
	if (cc <= blk) {
		for (const auto v : g[u]) {
			if (v == fa || low[v] == INF) {
				continue;
			}
			if (cc == 2) {
				meow(v, u, 1, fill);
			} else {
				meow(v, u, blk, fill);
			}
		}
		return;
	}
	for (const auto v : g[u]) {
		if (v == fa || low[v] == INF) {
			continue;
		}
		meow(v, u, blk, true);
	}
}*/
int ans;
bool marked[N];
void mark(const int u) {
	for (const auto v : g[u]) {
		if (f[v] && !marked[v]) {
			marked[v] = true;
			mark(v);
		}
	}
}
bool check() {
	rep(i, 1, n) {
		marked[i] = false;
	}
	int cnt = 0;
	rep(i, 1, n) {
		if (!marked[i] && f[i]) {
			marked[i] = true;
			mark(i);
			++ cnt;
		}
	}
	return cnt <= 2;
}
int dep[N];
void calc(const int u, const int fa, const int dp) {
	dep[u] = min(dep[u], dp);
	for (const auto v : g[u]) {
		if (v != fa) {
			calc(v, u, dp + 1);
		}
	}
}
int calc() {
	rep(i, 1, n) {
		dep[i] = INF;
	}
	rep(i, 1, n) {
		if (f[i]) {
			calc(i, 0, 0);
		}
	}
	int res = 0;
	rep(i, 1, n) {
		res = max(res, dep[i]);
	}
	return res;
}
void dfs(const int step, const int col) {
	if (step == n + 1) {
		if (col == k && check()) {
			ans = min(ans, calc());
		}
		return;
	}
	f[step] = true;
	dfs(step + 1, col + 1);
	f[step] = false;
	dfs(step + 1, col);
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> C >> T;
	while (T --) {
		cin >> n >> k;
		rep(i, 1, n) {
			g[i].clear();
		}
		rep(i, 1, n - 1) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans = INF;
		dfs(1, 0);
		cout << ans << '\n';
/*		int l = 0, r = n, ans = n;
		while (l <= r) {
			const int mid = (l + r) / 2;
			if (check(mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		cout << ans << '\n';*/
	}
	return 0;
}
