#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

int n, k, L, res;
vector<int> e[N + 10], adj[N + 10];
array<int, 3> f[N + 10], pre[N + 10], suf[N + 10];

void merge(array<int, 3> &x, array<int, 3> &y) {
	if (!y[0]) {
		if (!x[0]) {
			x[1] = max(x[1], y[1] + 1);
			if (x[1] >= L) x[0] = 1, x[1] = 0, x[2] = 1;
		}
		else if (y[0] + 1 == L) {
			x[2] += x[1]; x[1] = 0;
		}
	}
	else if (y[0]) {
		if (!x[0]) {
			if (x[1] + y[1] + 1 > L) {
				x[0] = 1, x[2] = y[2] + (x[1] + y[1] + 1 - L);
				x[1] = y[1] - (x[1] + y[1] - L);
			}
			else {
				x[0] = 1, x[1] = y[1] + 1, x[2] += y[2];
			}
		}
		else {
			x[2] += y[2] + x[1] + y[1]; x[1] = 0;
		}
	}
}

int get(array<int, 3> x, array<int, 3> y) {
	if (!x[0] && !y[0]) return 1;
	else if (!x[0]) {
		if (x[1] + y[1] + 1 <= L) return y[2];
		else return y[2] + x[1] + y[1] + 1 - L;
	}
	else if (!y[0]) {
		if (x[1] + y[1] + 1 <= L) return x[2];
		else return x[2] + x[1] + y[1] + 1 - L;
	}
	else return x[2] + y[2];
}

void dfs_init(int pa, int u) {
	for (int i = 0; i < e[u].size(); ++i) {
		int v = e[u][i]; if (v == pa) continue;
		adj[u].push_back(v); dfs_init(u, v);
	}
}

void dfs1(int u) {
	f[u][0] = 0, f[u][1] = 0, f[u][2] = 0;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i]; dfs1(v); merge(f[u], f[v]);
	}
	// cout << u << ' ' << f[u][0] << ' ' << f[u][1] << ' ' << f[u][2] << '\n';
}

void dfs2(int u, array<int, 3> up) {
	res = min(res, get(f[u], up));
	// if (L == 1 && get(f[u], up) <= k) {cout << "wow" << endl;}
	// cout << u << ' ' << f[u][0] << ' ' << f[u][1] << ' ' << f[u][2] << ' ' << up[0] << ' ' << up[1] << ' ' << up[2] << '\n'; 
	if (adj[u].empty()) return;
	
	int m = adj[u].size() - 1;
	pre[0][0] = pre[0][1] = pre[0][2] = 0; merge(pre[0], up);
	for (int i = 0; i < m; ++i) {
		pre[i + 1] = pre[i]; merge(pre[i + 1], f[adj[u][i]]);
	}
	suf[m][0] = suf[m][1] = suf[m][2] = 0;
	for (int i = m; i > 0; --i) {
		suf[i - 1] = suf[i]; merge(suf[i - 1], f[adj[u][i]]);
	}
	// cout << suf[0][0] << ' ' << suf[0][1] << ' ' << suf[0][2] << '\n';
	
	for (int i = 0; i <= m; ++i) {
		int flag = pre[i][0] && suf[i][0] && !pre[i][1] && !suf[i][1] ? 1 : 0;
		// cout << pre[i][0] << ' ' << pre[i][1] << ' ' << pre[i][2] << ' ' << suf[i][0] << ' ' << suf[i][1] << ' ' << suf[i][2] << '\n';
		--suf[i][1]; merge(pre[i], suf[i]); pre[i][2] -= flag; dfs2(adj[u][i], pre[i]);
	}
}

void baoli(int pa, int u) {
	f[u][0] = 0, f[u][1] = 0, f[u][2] = 0;
	for (int i = 0; i < e[u].size(); ++i) {
		int v = e[u][i]; if (v == pa) continue;
		baoli(u, v); merge(f[u], f[v]);
	}
	// cout << u << ' ' << f[u][0] << ' ' << f[u][1] << ' ' << f[u][2] << '\n';
}

bool check(int _L) {
	L = _L, res = n + 1;
	if (n <= 4000) {
		for (int u = 1; u <= n; ++u) {
			for (int i = 0; i < adj[u].size(); ++i) {
				int v = adj[u][i];
				baoli(u, v); baoli(v, u);
				res = min(res, get(f[u], f[v]));
	//			if (L == 1) {
	//				cout << u << ' ' << f[u][0] << ' ' << f[u][1] << ' ' << f[u][2] << '\n';
	//				cout << v << ' ' << f[v][0] << ' ' << f[v][1] << ' ' << f[v][2] << '\n';
	//				cout << get(f[u], f[v]) << '\n';
	//			}
			}
		}
	}
	else {
		dfs1(1); dfs2(1, {0, -1, 0});
	}
	return res <= k;
}

void work() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) e[i].clear(), adj[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	if (k == n) {cout << 0 << '\n'; return;}
	dfs_init(0, 1);
	
	int l = 1, r = n - 2, ans = n - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << '\n';
}

int main() {
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _c, T; cin >> _c >> T; while (T--) work();
	return 0;
}

// chennie bless me

/*
0 1
5 2
1 2
2 3
3 4
4 5

1

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

2

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

1
2
*/
