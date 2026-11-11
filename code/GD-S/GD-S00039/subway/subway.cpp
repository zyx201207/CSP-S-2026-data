#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int, int> pi;
const int N = 5e5 + 114 + 514, M = 555, INF = 1e18;
vector<pi> blgt[N];
int w[N];
int g[M][M], c, n, m, dd, q;
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> dd >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			blgt[a].push_back({i, t});
		}
	} 
//	cerr << "DIJ\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			g[i][j] = INF;
			if(i == j) g[i][j] = 0;
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < blgt[i].size(); j++) {
			for(int k = 0; k < blgt[i].size(); k++) {
				if(j == k) continue;
				g[blgt[i][j].first][blgt[i][k].first] = min(g[blgt[i][j].first][blgt[i][k].first], blgt[i][j].second + blgt[i][k].second);
				g[blgt[i][k].first][blgt[i][j].first] = min(g[blgt[i][k].first][blgt[i][j].first], g[blgt[i][j].first][blgt[i][k].first]);
			
			}
		}
	} 
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) cout << i << " to " << j << " cost " << g[i][j] << "\n";
	}
//	cerr << "FLOYD OK\n";
	for(int i = 1; i <= q; i++) {
//		cerr << "QUERY " << i << "\n";
		int x, y;
		cin >> x >> y;
		int ans = INF;
//		cerr << blgt[x].size() << " " << blgt[y].size() << "\n";
		for(int i = 0; i < blgt[x].size(); i++) {
			for(int j = 0; j < blgt[y].size(); j++) {
				ans = min(ans, g[blgt[x][i].first][blgt[y][j].first] + blgt[x][i].second + blgt[y][j].second);
			}
		}
		if(x == y) ans = 0;
		if(ans == INF) {
			cout << "NO Solution\n";
			continue;
		}
		cout << w[x] + w[y] + ans << "\n";
	}
	
	return 0;
} 

