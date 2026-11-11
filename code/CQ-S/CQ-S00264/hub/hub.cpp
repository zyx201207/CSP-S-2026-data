#include <bits/stdc++.h>
#define ll long long 
using namespace std;
constexpr int N = 1e6 + 5;
mt19937 rnd(time(nullptr));
int n, k;
int g[N], tot, mx;
int cnt, head[N];
struct edge{
	int to, nxt;
} e[N << 1];
struct node{
	int u, fa, dep;
};
void addedge(const int u, const int v) {
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
void init() {
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		head[i] = -1;
	}
}
map<int, bool> mp;
bool vis[N];
void gen() {
	mp.clear();
	tot = 0, mx = 0;
	while (tot < k) {
		const int tp = rnd() % n + 1;
		if (!mp[tp]) {
			mp[tp] = true;
			g[++tot] = tp;
		}
	}
}
void bfs() {
	queue<node> q;
	for (int i = 1; i <= n; ++i) vis[i] = false;
	for (int i = 1; i <= k; ++i) {
		q.push({g[i], 0, 0});
	}
	while (!q.empty()) {
		const int u = q.front().u, fa = q.front().fa, dep = q.front().dep;
		q.pop();
		if (vis[u]) continue;
		if (dep > mx) mx = dep;
		vis[u] = true;
		for (int i = head[u]; ~i; i = e[i].nxt) {
			const int v = e[i].to;
			q.push({v, u, dep + 1});
		}
	}
}
int f[N];
bool check() {
	for (int i = 1; i <= n; ++i) f[i] = i;
	int sum = 0;
	for (int u = 1; u <= k; ++u) {
		for (int i = head[u]; ~i; i = e[i].nxt) {
			const int v = e[i].to;
			if (mp[v] && f[u] != f[v]) {
				f[u] = f[v];
				++sum;
			}
		}
	}
	if (k - sum > 2) return false;
	return true;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		init();
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			addedge(u, v);
			addedge(v, u);
		}
		int ans = 1e9;
		for (int p = 1; p <= 20; ++p) {
			gen();
			bfs();
			if (check()) {
				ans = min(ans, mx);
			}
		}
		cout << ans << '\n';
	} 
	return 0;
}

// start on 17:10; complete on 18:19; check on 18:23
