#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 10;
int ccf, n, m, d, q;
int w[M], f[N][N];
vector<pair<int, int>> g[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> ccf >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t;
			cin >> a >> t;
			g[a].push_back({i, t});
		}
	}
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n; i++){
		f[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int u = 0; u < g[i].size(); u++){
			for(int v = u + 1; v < g[i].size(); v++){
				int x = g[i][u].first;
				int y = g[i][v].first;
				f[x][y] = f[y][x] = min(f[x][y], g[i][u].second + g[i][v].second);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = f[j][i] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for(auto u : g[x]){
			int t = u.first;
			int wt = u.second;
			for(auto v : g[y]){
				int p = v.first;
				int wp = v.second;
				ans = min(ans, wt + wp + f[t][p]);
			}	
		}
		cout << w[x] + w[y] + ans << '\n';
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
