#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

constexpr int INF = INT_MAX;

#define int long long
typedef long long ll
const int M = 5e5 + 5;
vector<ll> link[51][51];
vector<ll> line[51];
vector<ll> road[M][M];
ll w[M];
ll tim[M][51];
ll in_line[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		ll k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			ll a, t;
			cin >> a >> t;
			if (!in_line[a])
				in_line[a] = i;
			else {
				link[i][in_line[a]].push_back(a);
				link[in_line[a]][i].push_back(a);
			}
				
			line[i].push_back(a);
			tim[i][a] = t;
		}
	}
	
	vector<vector<ll>> dist(m + 1, vector<ll>(m + 1, INF));
	for (int u = 1; u <= m; ++u) {
		for (int v = 1; v <= m; ++v) {
			if (u == v) {
				dist[u][v] = 0;
				continue;
			}
			
			if (in_line[u] == in_line[v]) {
				dist[u][v] = 0;
				continue;
			}
			
			if (link[in_line[u]][in_line[v]].size() > 0) {
				dist[u][v] = 1;
				break;
			}
		}
	}
	
	for (int k = 1; k <= m; ++k) {
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (dist[i][k] == INF || dist[k][j] == INF) {
					continue;
				}
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					road[i][j].push_back(in_line[k]);
				}
			}
		}
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		
		vector<int> tmp;
		for (int i = 1; i <= n; ++i) {
			if (road[x][y][i]) {
				tmp.push_back(i);
			}
		}
		
		vector<ll> res;
		for (ll a : tmp) {
			for (ll b : tmp) {
				if (a == b) continue;
				ll cur = LONG_LONG_MAX;
				for (ll u : link[a][b]) {
					cur = min(tim[u][a] + tim[u][b], cur);
				}
				res.push_back(cur);
			}
		}
		
		sort(res.begin(), res.end());
		
		ll ans = 0;
		for (int i = 1; i <= dist[x][y]; ++i) {
			ans += res[i];
		}
		
		cout << ans << endl;
	}
	return 0;
}

