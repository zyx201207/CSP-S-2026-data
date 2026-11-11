#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int N = 5e5 + 5;
const ull INF = 1e18;

int c, n, m, d, q;
ull w[N];
int a[N];
ull t[N];
vector<pair<int, ull>> adj[N];

ull solve(int x, int y) {
	vector<ull> dist(m, INF);
	dist[x] = 0;
	priority_queue<pair<ull, int>, vector<pair<ull, int>>, greater<pair<ull, int>>> pq;
	pq.emplace(0, x);
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		ull d = p.first, u = p.second;
		if (d != dist[u]) continue;
		for (auto &e : adj[u]) {
			ull v = e.first, w = e.second;
			if (dist[v] > d + w) {
				dist[v] = d + w;
				pq.emplace(dist[v], v);
			}
		}
	}
	return dist[y] + w[x] + w[y];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> a[j] >> t[j];
		}
		for (int j = 1; j <= k; ++j) {
			for (int l = j + 1; l <= k; ++l) {
				adj[a[j]].emplace_back(a[l], t[j] + t[l]);
				adj[a[l]].emplace_back(a[j], t[j] + t[l]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}
	return 0;
} 
