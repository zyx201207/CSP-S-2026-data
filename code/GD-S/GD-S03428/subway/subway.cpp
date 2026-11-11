#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr long long INF64 = 1e18;

struct Ed {
	int v, w;
};

struct Ps {
	int u;
	long long w;
	bool operator>(const Ps &oth) const {
		return w > oth.w;
	}
};

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	vector<vector<Ed>> g(m + 1);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		int a, t;
		cin >> a >> t;
		g.push_back(vector<Ed>());
		g[g.size() - 1].push_back({a, t});
		g[a].push_back({(int)g.size() - 1, t});
		for (int j = 1; j < k; j++) {
			int a, t;
			cin >> a >> t;
			g.push_back(vector<Ed>());
			g[g.size() - 1].push_back({a, t});
			g[a].push_back({(int)g.size() - 1, t});
			g[g.size() - 1].push_back({(int)g.size() - 2, 0});
			g[g.size() - 2].push_back({(int)g.size() - 1, 0});
		}
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		priority_queue<Ps, vector<Ps>, greater<Ps>> pq;
		vector<long long> dis(g.size(), INF64);
		pq.push({x, 0});
		dis[x] = 0;
		while (!pq.empty()) {
			const Ps cu = pq.top();
			const int u = cu.u;
			const long long w = cu.w;
			if (u == y) break;
			pq.pop();
			for (const Ed &e : g[u]) {
				if (w + e.w < dis[e.v]) {
					pq.push({e.v, w + e.w});
					dis[e.v] = w + e.w;
				}
			}
		}
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	cout << flush;
} 
