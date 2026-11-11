#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 507, M = 5e5 + 7;
int c, n, m, d, q;
int w[M];
int head[N], dis[N], cnt;
bool vis[N];

struct Edge {
	int to, nxt, len;
} e[M];

struct node {
	int pos, dis;
	bool operator < (const node &x) const {
		return dis > x.dis;
	}
};

inline void add (int u, int v, int val) {
	e[++ cnt] = {v, head[u], val};
	head[u] = cnt;
}

inline void Dijkstra (int s) {
	for (int i = 1; i <= n; i ++) {
		dis[i] = 0x7f7f7f7f;
		vis[i] = 0;
	}
	priority_queue<node> Q;
	Q.push(node{s, 0});
	dis[s] = 0; vis[s] = 1;
	while (!Q.empty()) {
		int u = Q.top().pos; Q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (dis[v] + e[i].len + w[u] < dis[u]) {
				dis[u] = dis[v] + e[i].len + w[u];
				Q.push(node{v, dis[v]});
			}
		}
	}
	return;
}

int32_t main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i ++) {
		cin >> k;
		for (int j = 1, a, t; j <= k; j ++) {
			cin >> a >> t;
			add(k, a, t);
		}
	}
	for (int i = 1, x, y; i <= q; i ++) {
		cin >> x >> y;
		Dijkstra(x);
		cout << dis[y] << "\n";
	}
	return 0;
}
