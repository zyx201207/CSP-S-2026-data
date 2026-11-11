#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c, n, m, d, q;
int w[500006];
vector <int> jg[500006];
int val[500006][505]; 
long long g[505][505];
long long dp[505][505];

//int floyd(int x, int y){
//	memset(dp, 0x3f, sizeof(dp));
//	for (int i = 1;i <= n;i++){
//		dp[n] = min(dp[n - 1], (long long)g[x][k] + g[k][y]);
//	}
//}

int main (){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)    cin >> w[i];
	for (int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++){
			int a, t;
			cin >> a >> t;
			jg[a].push_back(i);
			val[a][i] = t;
		}
	}
	for (int i = 0;i < n + 1;i++){
		for (int j = 0;j < n + 1;j++){
			g[i][j] = 0x7ffffffffffffff;
//			g[i][j] = 0x7fffffff;
		}
	}
	for (int i = 1;i <= m;i++){
		for (int j = 0;j < jg[i].size();j++){
			for (int k = j;k < jg[i].size();k++){
				g[jg[i][j]][jg[i][k]] = min(g[jg[i][j]][jg[i][k]], (long long)(val[i][jg[i][j]]) + (long long)(val[i][jg[i][k]]));
				g[jg[i][k]][jg[i][j]] = g[jg[i][j]][jg[i][k]];
			}
		}
	}
	for (int i = 0;i <= n;i++){
		for (int j = 0;j <= n;j++){
				dp[i][j] = 0x7fffffffffffffff;
		}
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			dp[i][j] = g[i][j];
		}
	}
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			for (int j = i;j <= n;j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				dp[j][i] = dp[i][j];
			}
		}
	}
	while (q--){
		long long ans = 0x7fffffffffffffff;
//		int xl1 = 0, xl2 = 0;
		int x, y;
		cin >> x >> y;
		for (int i = 0;i < jg[x].size();i++){
			for (int j = 0;j < jg[y].size();j++){
				long long tmp = 0x7fffffffffffffff;
				if (jg[x][i] == jg[y][j]){
					tmp = val[x][jg[x][i]] + val[y][jg[y][j]];
				}
				else{
					tmp = dp[jg[x][i]][jg[y][j]] + val[x][jg[x][i]] + val[y][jg[y][j]];
				}
				ans = min(tmp, ans);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
//		here:
//			cout << "\n";
	}
	return 0;
} 
