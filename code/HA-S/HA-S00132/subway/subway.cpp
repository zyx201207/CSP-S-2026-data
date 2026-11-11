#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<long long, int> pii;
const int N = 5e5 + 5;

/*
15:34 pretest 1-4 accepted
tle on oth

solve other problem
*/

int c, n, m, d, q;
struct edge {
	ll v, w;
};
vector<edge> g[N];
ll w[N];

ll dist[N];
	
int x, y;
void dij() {
	for (int i = 1; i <= m; i ++) {
		dist[i] = 1e18;
	}
	dist[x] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, x});
	while (!pq.empty()) {
		auto c = pq.top();
		pq.pop();
		int u = c.second;
		if (dist[u] != c.first) continue;
		for (auto e : g[u]) {
			int v = e.v;
			if (dist[v] > 0ll + dist[u] + e.w) {
				dist[v] = dist[u] + e.w;
				pq.push({dist[v], v});
			}
		}
	}
	
	
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		if (k == 1) {
			cin >> k;
			continue;
		}
		vector<int> v, tv;
		for (int j = 1; j <= k; j ++) {
			int t, tt;
			cin >> t >> tt;
			v.push_back(t);
			tv.push_back(tt);
		}
		for (int j = 0; j < k; j ++) {
			for (int z = j + 1; z < k; z ++) {
				ll w = tv[j] + tv[z];
				g[v[j]].push_back({v[z], w});
				g[v[z]].push_back({v[j], w});
			}
		}
	}
	
	while (q --) {
		cin >> x >> y;
		dij();
		cout << dist[y] + w[x] + w[y] << "\n";
	}

	return 0;
}

