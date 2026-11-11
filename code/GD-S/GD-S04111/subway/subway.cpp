#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, int> P;

const ll INF = 4e18;

struct E {
	int v, t;
};

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	vector<int> w(m + 1);
	for (int i = 1; i <= m; ++i) cin >> w[i];
	
	vector<vector<E>> g(m + n + 5);
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		for (int j = 0; j < k; ++j) {
			int a, t;
			cin >> a >> t;
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	}
	
	for (int i = 0; i < q; i++) {
		int x, y; cin >> x >> y;
		vector<ll> dist(m + n + 5, INF);
		priority_queue<P, vector<P>, greater<P>> pq;
		dist[x] = 0;
		pq.push(P(0, x));
		while(!pq.empty()) {
			ll d = pq.top().first;
			int u = pq.top().second;
			pq.pop();
			
			if (d > dist[u]) continue;
			
			for (auto e : g[u]) {
				int v = e.v, t = e.t;
				if (d + t < dist[v]) {
					dist[v] = d + t;
					pq.push({dist[v], v});
				}
			}
		}
		
		cout << dist[y] + w[x] + w[y] << '\n';
	}
	
	return 0;
} 
