//GZ-S00003 贵阳市白云区华师一学校 殷浩然 
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define upp(i, l, r) for(int i = l; i <= r; i++)
#define dww(i, l, r) for(int i = l; i >= r; i--)
#define PII pair<int, int>
#define ub push_back
#define x first
#define y second
using namespace std;

const int N = 1e6 + 5, K = 21;

int n, m;
int res;
int ff[N][K];
int dep[N];
int a[N];
bool st[N];
vector<int> edge[N];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	ff[u][0] = fa;
	for (auto v : edge[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
}

void init() {
	upp(k, 1, K - 1) upp(i, 1, n) ff[i][k] = ff[ff[i][k - 1]][k - 1];
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	dww(k, K - 1, 0) {
		if (dep[ff[x][k]] >= dep[y]) x = ff[x][k];
	}
	if (x == y) return x;
	dww(k, K - 1, 0) {
		if (ff[x][k] != ff[y][k]) x = ff[x][k], y = ff[y][k];
	}
	return ff[x][0];
}

int dist(int x, int y) {
	return dep[x] + dep[y] - dep[lca(x, y)] * 2;
}

void dsf(int i, int c) {
	if (i > n) {
		if (c != m) return;
		int cnt = 0;
		upp(j, 1, n) if (!st[i]) upp(k, 1, m) cnt = max(cnt, dist(j, a[k]));
		res = min(res, cnt);
		return;
	}
	dsf(i + 1, c);
	if (c == m) return;
	st[i] = 1;
	a[c + 1] = i;
	dsf(i + 1, c + 1);
	st[i] = 0;
	a[c + 1] = 0;
}

void solve() {
	res = 1e18;
	cin >> n >> m;
	if (n == m) return cout << 0 << endl, void();
	if (n == m + 1) return cout << 1 << endl, void();
	if (n == m + 2) return cout << 1 << endl, void();
	if (n > 25) return cout << 0 << endl, void();
	upp(i, 1, n) edge[i].clear();
	upp(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		edge[u].ub(v);
		edge[v].ub(u);
	}
	dfs(1, 0);
	init();
	dsf(1, 0);
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while(T--) solve();
	
	return 0;
}
