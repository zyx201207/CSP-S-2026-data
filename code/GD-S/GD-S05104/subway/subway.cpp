#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 505;
const int M = 5e5 + 5;
const int inf = 0x3f3f3f3f;
struct Edge {
	int v, w;
	Edge (int v, int w) : v(v), w(w) {};
};
struct Node {
	int u, dis;
	Node (int u, int dis) : u(u), dis(dis) {};
	bool operator < (const Node &other) const {
		return dis > other.dis;
	}
};
int c, n, m, d, q;
int w[M], a[N][N], t[N][N], k[N];
ll dis[N];
vector<Edge> G[M];
inline void dij(int s, int t) {
	fill(dis, dis + N, inf);
	priority_queue<Node> pq;
	dis[s] = 0;
	pq.emplace(s, dis[s]);
	while (!pq.empty()) {
		int u = pq.top().u;
		int curr = pq.top().dis;
		pq.pop();
		if (curr > dis[u]) continue;
		if (u == t) break;
		for (auto &e : G[u]) {
			int v = e.v, w = e.w;
			int new_dis = dis[u] + w;
			if (new_dis < dis[v]) {
				dis[v] = new_dis;
				pq.emplace(v, dis[v]);
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i {1}; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i {1}; i<= n; ++i) {
		cin >> k[i];
		for (int j {1}; j <= k[i]; ++j) {
			cin >> a[i][j] >> t[i][j];
			for (int u {1}; u < j; ++u) {
				G[a[i][u]].emplace_back(a[i][j], t[i][u]);
				G[a[i][j]].emplace_back(a[i][u], t[i][j]);
			}
		}
	}
	while (q--) {
		int s, t;
		cin >> s >> t;
		if (s == t) {
			cout << 0 << '\n';
			continue;
		}
		dij(s, t);
		cout << w[s] + w[t] + dis[t] << '\n';
	}
	return 0;
}
