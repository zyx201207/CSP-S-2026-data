#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i <= b; i ++ )
#define per(i, a, b) for (int i = a; i >= b; i -- )
#define pb push_back
void _max(int &a, int b) {a = max(a, b); }
void _min(int &a, int b) {a = min(a, b); }

// hub

const int N = 1e5 + 5;

int n, k;
vector <int> e[N];
int updiv(int a, int b) {
	return (a + b - 1) / b;
}

void solveA() {
	cin >> n >> k;
	rep(i, 1, n - 1) {
		int u, v; cin >> u >> v;
//		e[u].pb(v);
//		e[v].pb(u);
	}
	int m = n / 2;
	if (k == n) cout << "0\n";
	else if (k >= m) cout << "1\n";
	else cout << (updiv(m + 1 - k, 4) + 1) << '\n';
	return ;
}
bool vis[N]; int dis[N];
void bfs(int x, int y, int &ans) {
	for (auto v : e[x]) 
		if (v == y) return ;
	rep(i, 1, n) vis[i] = 0, dis[i] = n + 1;
	dis[x] = 0, dis[y] = 0;
	queue <int> q;
	q.push(x); q.push(y);
	int mx = 0;
	while (q.size()) {
		int u = q.front(); q.pop();
		mx = max(mx, dis[u]);
		vis[u] = 1;
		if (dis[u] >= ans) return ;
		for (auto v : e[u]) {
			if (vis[v]) continue;
			vis[v] = 1;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
	ans = mx;
}
void solveB() {
	cin >> n >> k;
	rep(i, 1, n) e[i].clear();
	rep(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	int res = n + 1;
	rep(i, 1, n)
		rep(j, 1, n)
			bfs(i, j, res);
	cout << res << '\n';
	return ;
}
int p[N];
int find(int x) {
	return p[x] == x ? p[x] : p[x] = find(p[x]);
}
void merge(int u, int v) {
	u = find(u), v = find(v);
	p[u] = v;
}
void solvebru() {
	cin >> n >> k;
	rep(i, 1, n) e[i].clear();
	rep(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	int ans = n + 1;
	rep(j, 1, (1 << n) - 1) {
		int _t = __builtin_popcount(j);
		if (_t != k) continue;
		rep(i, 1, n) p[i] = 0;
		rep(i, 1, n) if (j & (1 << (i - 1))) p[i] = i;
		rep(i, 1, n) 
			if (j & (1 << (i - 1)))
				for (auto v : e[i]) 
					if (p[v])
						merge(i, v);
		int cnt = 0;
		rep(i, 1, n) if (p[i] == i) cnt ++ ;
		if (cnt != 2) continue;
		rep(i, 1, n) vis[i] = 0, dis[i] = n + 1;
		queue <int> q;
		rep(i, 1, n) 
			if (j & (1 << (i - 1))) 
				dis[i] = 0, q.push(i), vis[i] = 1;
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto v : e[u]) {
				if (vis[v]) continue;
				vis[v] = 1;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		int res = 0;
		rep(i, 1, n) _max(res, dis[i]);
		_min(ans, res);
	}
	cout << ans << '\n';
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T = 1;
	cin >> c >> T;
	if (c == 13 || c == 14) while (T -- ) solveA();
	else if (c == 7 || c == 11 || c == 12) while (T -- ) solveB();
	else while (T -- ) solvebru();
	return 0;
}

