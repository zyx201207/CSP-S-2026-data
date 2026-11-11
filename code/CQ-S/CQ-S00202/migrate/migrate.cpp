#include <bits/stdc++.h>
using namespace std;

#define DEBUG
#define LOCAL

typedef long long int ll;
typedef unsigned long long int ull;
#define int ll

const int N = 5e3 + 10, M = 2e5 + 10, INF = 4e18, mod = 1e9 + 7;
int n, m, k, cnt, ans, edge_cnt = 1;
int a[N], head[N];

struct Edge {
	int u, v, w, next;
	Edge(int _u = 0, int _v = 0, int _w = 0, int _next = 0): u(_u), v(_v), w(_w), next(_next) {}
} edge[2 * N * N];

struct PQNode {
	int dis, i;
	PQNode(int _dis = 0, int _i = 0): dis(_dis), i(_i) {}
	inline bool operator < (const PQNode& other) const {
		return dis > other.dis;
	} 
};

inline void add(int u, int v, int w) {
	edge[edge_cnt] = Edge(u, v, w, head[u]);
	head[u] = edge_cnt ++;
}

inline void init() {
	for (int i = 1; i <= n; i ++) {
		head[i] = 0;
	}
	
	edge_cnt = 1;
}

inline int Dijkstra(int st) {
	priority_queue<PQNode> pq;
	vector<int> dist(n + 1, INF), cnt(n + 1, 0);
	vector<bool> vis(n + 1, 0);
	
	pq.push(PQNode(0, st));
	dist[st] = 0;
	cnt[st] = 1;
	
	while (!pq.empty()) {
		int u = pq.top().i, dis = pq.top().dis;
		pq.pop();
		
		for (int i = head[u]; i; i = edge[i].next) {
			int v = edge[i].v;
			if (dist[v] > dis + 1) {
				dist[v] = dis + 1;
				cnt[v] = cnt[u];
				if (!vis[v]) {
					vis[v] = 1;
					pq.push(PQNode(dist[v], v));
				}
			} else if (dist[v] == dist[u] + 1) {
				cnt[v] ++;
			}
		}
	}
	
	int res = 0;
	for (int i = 1; i <= n; i ++) {
		if (cnt[i] == 2) res ++;
	}
	
	return res;
}

inline void solve() {
	cin >> n >> m;
	
	vector<int> x(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> x[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (abs(x[i] - x[j]) <= m) {
				add(i, j, abs(x[i] - x[j]));
			}
		}
	}
	ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += Dijkstra(i);
	}
	
	cout << ans << "\n";
	init();
}
#undef int
int main(int argc, const char* argv[]) {
#define int ll
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int test_case = 0;
	int t = 1;
	cin >> test_case >> t;

	while (t --) {
		solve();
	}

	return 0;
}

