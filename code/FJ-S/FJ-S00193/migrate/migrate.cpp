#include <iostream>
#include <vector>
#include <climits>
using namespace std;

constexpr long long INF = LONG_LONG_MAX; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while (t--) {
		int n, d;
		cin >> n >> d;
		
		vector<long> x(n + 1);
		vector<vector<long>> dist(n + 1, vector<long>(n + 1, INF));
		
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
			dist[i][i] = 0;
			long dd = x[i] - x[i - 1];
			dist[i][i - 1] = (dd <= d) ? dd : INF;
			dist[i - 1][i] = (dd <= d) ? dd : INF;
		}
		
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (dist[i][k] == INF || dist[k][j] == INF)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		
		long ans = 0;
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (dist[i][k] + dist[k][j] == dist[i][j]) {
						++ans;
					}
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}

