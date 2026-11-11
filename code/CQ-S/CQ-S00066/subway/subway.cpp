#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5;
const int MAXM = 500;
const int MAXQ = 1e5;

ull to[MAXN | 1][MAXM | 1];
ull dist[MAXN | 1][MAXM | 1];
uint64_t request[MAXQ | 1];
int request_id[MAXQ | 1];
ull ans[MAXQ | 1];
vector<int> mpth[MAXN | 1];
vector<int> path[MAXM | 1];
int a[MAXN | 1];

void solve_dist(int n, int m, int x) {
	memset(dist, 0xFF, (n * m) << 3);
	priority_queue<pair<ull, uint64_t>, vector<pair<ull, uint64_t>>, greater<pair<ull, uint64_t>>> pq;
	for (auto p : mpth[x]) {
		pq.emplace(to[x][p], ((uint64_t)p << 32 | x));
	}
	while (!pq.empty()) {
		auto p = pq.top(); pq.pop();
		uint32_t u = (uint32_t)p.second;
		uint32_t id = p.second >> 32;
		ull d_ = p.first;
		if (d_ > dist[u][id]) continue;
		
		for (auto p : mpth[u]) {
			ull d = d_;
			if (p != id) d += to[u][id] + to[u][p];
			for (auto v : path[p]) {
				if (v == u) continue;
				if (d < dist[v][p]) {
					pq.emplace(d, (uint64_t)p << 32 | v);
				}
			}
		}
	}
}

ull solve(int u, int v) {
	ull mn = -1ULL;
	for (auto p : path[v]) {
		ull cur = dist[v][p] + to[v][p];
		if (cur < mn) {
			mn = cur;
		}
	}
	return mn + a[u] + a[v];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int C, n, m, D, Q;
	scanf("%d%d%d%d%d", &C, &n, &m, &D, &Q);
	
	for (int i = 1; i <= m; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		path[i].resize(k);
		for (int j = 0; j < k; ++j) {
			int t;
			scanf("%d%d", &path[i][j], &t);
			to[path[i][j]][i] = t;
			mpth[path[i][j]].push_back(i);
		}
	}
	
	for (int i = 1; i <= Q; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		
		if (u > v) swap(u, v);
		request[i] = (uint64_t)u << 32 | v;
		request_id[i] = i; 
	}
	
	sort(request_id + 1, request_id + Q + 1, [&](int x, int y) -> bool {
		return request[x] < request[y];
	});
	
	int lst = 0;
	for (int i = 1; i <= Q; ++i) {
		int rid = request_id[i];
		int u = request[rid] >> 32;
		int v = request[rid];
		if (lst != u) solve_dist(m, n, u);
		ans[rid] = solve(u, v);
	}
	for (int i = 1; i <= Q; ++i) {
		printf("%llu\n", ans[i]);
	}
	return 0;
}

