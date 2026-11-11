//From: CSP-S
//Problem: T3迁徙（migrate）
//文件名: migrate.in/.out/.cpp
//时间限制: 1000 ms
//空间限制: 1024 MiB 
//预期得分: 0 pts 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int N = 2e6 + 10;
constexpr int N1 = 300 + 10;

int c, T;//多测 
int n;
ll d;
ll x[N];
vector <int> g[N1];
ll dist[N1][2];
int vis[N1];
struct Node {
	int u;
	__int128 w;
	bool operator < (const Node &others) const {
		return w < others.w;
	}
};
priority_queue <Node> q;

ll absll(ll x) {
	return (x > 0) ? x : -x;
}

int dijkstra(int s) {
	memset(dist, 0x7f, sizeof dist);
	memset(vis, 0, sizeof vis);
	while (!q.empty()) q.pop();
	q.push({s, 0});
	dist[s][0] = 0;
	while (!q.empty()) {
		Node p = q.top();
		q.pop();
		int u = p.u;
		__int128 w = p.w;
		for (int v : g[u]) {
//			cout << "to " << v << "\n";
			if (vis[v] >= 2) continue;
			if (dist[v][vis[v]] > dist[u][vis[u]] + absll(x[u] - x[v])) {
				dist[v][vis[v]] = dist[u][vis[u]] + absll(x[u] - x[v]);
				vis[v] ++;
//				cout << "ok" << "\n";
				q.push({v, dist[v][vis[v]]});
			}
		}
	}
//	for (int i = 1; i <= n; i ++) cout << "(" << dist[i][0] << ", " << dist[i][1] << ")";
//	cout << "\n";
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (s == i) continue;
		cnt += (dist[i][0] == dist[i][1] && vis[i]);
	}
	return cnt;
}

void solve1() {
	while (T --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> x[i];
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (i == j) continue;
				if (absll(x[i] - x[j]) > d) continue;
				g[i].push_back(j);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) ans += dijkstra(i);
		cout << ans / 2 << "\n"; 
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	if (1 <= c && c <= 10) solve1();
	else if (c == 0) solve1();
	return 0;
}
