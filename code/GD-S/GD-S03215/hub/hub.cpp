#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

bool c[N];
int n, k, ans, mid, tot, dis[N], h[N * 2], to[N * 2], nxt[N * 2];

void chkmn(int &x, int y) {
	x = x < y ? x : y;
}

void add(int u, int v) {
	to[++tot] = v;
	nxt[tot] = h[u];
	h[u] = tot;
}

pair<int, int> dfs2(int u, int fa) {
	pair<int, int> R = make_pair(c[u], c[u]);
	for (int i = h[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == fa)
			continue;
		pair<int, int> r = dfs2(v, u);
		R.first += r.first - (c[u] && r.second);
	}
	return R;
}

int bfs() {
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		dis[i] = 1e9;
		if (c[i])
			q.push(i), dis[i] = 0;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = h[u]; i; i = nxt[i]) {
			if (dis[to[i]] == 1e9) {
				dis[to[i]] = dis[u] + 1;
				q.push(to[i]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dis[i]);
	return ans;
}

int check() {
	if (dfs2(1, 0).first > 2)
		return 1e9;
	return bfs();
}

void dfs1(int x, int y) {
	if (y > k)
		return;
	if (x == n + 1) {
		ans = min(ans, check());
		return;
	}
	c[x] = 1, dfs1(x+1, y+1);
	c[x] = 0, dfs1(x+1, y);
}

void solve() {
	ans = 1e9, tot = 0, memset(h, 0, sizeof(h));
	cin >> n >> k;
	for (int i = 1, u, v; i < n; ++i)
		cin >> u >> v, add(u, v), add(v, u);
	dfs1(1, 0);
	cout << ans << '\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
