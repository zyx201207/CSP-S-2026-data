#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Min(a, b) a = min(a, b)
#define pp pair<int, int>
#define ft first
#define sd second
const int N = 505, M = 1005, F = 1e18;
int c, n, m, d, q, w[M], k[N];
int t[M][N], dp[M][N];
vector<int> g[N], xl[M];
//dp[i][j] 到达 i 地铁站 j 线路站台时的最少步行时间 
//t[i][j] 地铁站 i 的站厅到 j 线路站台时间 
//w[i]  从 i 地铁站的地铁口走到站厅需要的时间
//xl[i] 经过 i 地铁站的线路
//g[i]  i 线路的站点 
void make_dp(int x) {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = F;
	for (int i : xl[x]) dp[x][i] = t[x][i];
	while (1) {
		bool f = 0; 
		for (int i = 1; i <= m; i++) 
			for (int j : xl[i]) {
				int sum = F;
				for (int a : xl[i])
					if (a != j) {
						int z = dp[i][a] + t[i][a] + t[i][j];
						Min(sum, z);
					}
				if (sum < dp[i][j]) 
					dp[i][j] = sum, f = 1;
			}
		if (!f) break;
	}
	for (int i = 1; i <= n; i++) {
		int lst = 0;
		for (int j : g[i]) {
			if (lst) Min(dp[j][i], dp[lst][i]);
			lst = j;
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i]; int x;
		for (int j = 1; j <= k[i]; j++) {
			cin >> x >> t[x][i];
			g[i].push_back(x);
			xl[x].push_back(i);
		}
	} 
	while (q--) {
		int st, ed, mi = 1e18;
		cin >> st >> ed;
		make_dp(st);
		for (int i : xl[ed]) 
			Min(mi, dp[ed][i] + t[ed][i]);
		cout << w[st] + w[ed] + mi << "\n";
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
