#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 505, M = 5e5 + 5;

ll c, n, m, d, q;
ll w[N];
int b[M][N]; // 第i条路，点站台到站厅 
ll a[N][25][25]; // 从第 i 个点，从路线j到k的边权 
vector <ll> ve[N];
ll dis[N][N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		int _; cin >>_;
		while(_ --) {
			int u, k; cin >> u >> k;
			ve[u].push_back(i);
			b[i][u] = k;
		}
	}
	
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(i == j) continue;
			dis[i][j] = 0x3f3f3f3f;
		}
	}
	
	for(int i = 1; i <= m; i ++) {
		for(int j = 0; j < ve[i].size(); j ++) {
			for(int k = 0; k < ve[i].size(); k ++) {
				if(j == k) continue;
				int u = ve[i][j], v = ve[i][k];
				dis[u][v] = b[u][i] + b[v][i];
				dis[u][v] = b[u][i] + b[v][i];
			}
		}
	}
//	for(int i = 1; i <= 2; i ++) {
//		for(int j = 1; j <= 2; j ++) cout << dis[i][j] << " ";
//		cout << endl;	
//	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			for(int k = 1; k <= n; k ++) {
				dis[j][k] = min(dis[j][k], dis[i][j] + dis[i][k]);
			} 
		} 
	}

	for(int i = 1; i <= q; i ++) {
		int u, v; cin >> u >> v;
		int ans = 0x3f3f3f3f3f;
		for(int j = 0; j < ve[u].size(); j ++) {
			for(int k = 0; k < ve[v].size(); k ++) {
				int idu = ve[u][j], idv = ve[v][k];
				ans = min(ans, (int)(dis[idu][idv] + b[idu][u] + b[idv][v] + w[u] + w[v]));
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 	

/*
只能打部分分了
学了这么久结果只会用个Floyd，感觉我好废
也许这次比赛以后AFO了吧
[流泪] 
*/
