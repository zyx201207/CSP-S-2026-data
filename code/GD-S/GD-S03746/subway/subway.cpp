#include<bits/stdc++.h>
using namespace std;

#define int long long

int c, n, m, d, q;
const int M = 5e5 + 507;
const int INF = 0x3f3f3f3f3f3f3f3f;
int a[M];
struct Edge {
	int u, d;
};
struct Compare {
	bool operator() (const Edge &e1, const Edge &e2) {
		return e1.d > e2.d;
	}
};
vector<vector<Edge>> adj(M);
vector<int> dijkstra(int s) {
	vector<int> dist(M, INF);
	priority_queue<Edge, vector<Edge>, Compare> pq;
	pq.push({s, 0});
	dist[s] = 0;
	while (!pq.empty()) {
		Edge e = pq.top();
		pq.pop();
		int u = e.u, d = e.d;
		if (dist[u] < d) continue;
		for (auto to : adj[u]) {
			int v = to.u, w = to.d;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({v, dist[v]});
			}
		}
	}
	// for (int i = 1; i <= m; ++i) cout << dist[i] << " ";
	return dist;
}
void solve() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
	}
	bool flag = true;
	int TT = -1;
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		for (int j = 0; j < k; ++j) {
			int id, t;
			cin >> id >> t;
			adj[id].push_back({i + m, t});
			adj[i + m].push_back({id, t});
			if (TT == -1) TT = t;
			flag &= (TT == t);
		}
	}
	if (flag) {
		while (q--) {
			int x, y;
			cin >> x >> y;
			queue<int> q;
			q.push(x);
			vector<int> dist(M, INF);
			dist[x] = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (auto to : adj[u]) {
					int v = to.u;
					if (dist[v] > dist[u] + 1) {
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}
			cout << a[x] + a[y] + dist[y] * TT << endl;
		}
		return;
	}
//	for (int i = 1; i <= m; ++i) {
//		cout << i << ":";
//		for (auto to : adj[i]) {
//			cout << to.u << " ";
//		}
//		cout <<endl;
//	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		vector<int> dist = dijkstra(x);
		cout << dist[y] + a[x] + a[y] << endl;
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
