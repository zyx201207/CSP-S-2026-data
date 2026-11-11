#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 510, M = 5e5 + 10;

LL dist[N][N];
LL walk[M];
vector<pair<int, LL>> station[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	
	memset(dist, 0x3f, sizeof dist);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i ++ ) cin >> walk[i];
	for (int i = 1; i <= n; i ++ ) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j ++ ) {
			int a; LL t;
			cin >> a >> t;
			station[a].push_back({i, t});
		}
		dist[i][i] = 0;
	}
	for (int i = 1; i <= m; i ++ ) {
		for (auto la : station[i]) {
			for (auto lb : station[i]) {
				dist[la.first][lb.first] = min(dist[la.first][lb.first], la.second + lb.second);
			}
		}
	}
	for (int k = 1; k <= n; k ++ ) 
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ ) 
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	while (q -- ) {
		int x, y;
		cin >> x >> y;
		LL ans = 0x7fffffffffffffff;
		for (auto la : station[x]) 
			for (auto lb : station[y])
				ans = min(ans, la.second + lb.second + dist[la.first][lb.first]);
		cout << ans + walk[x] + walk[y] << endl;
	}
	return 0;
}
