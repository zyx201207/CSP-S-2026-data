#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 507, M = 5e5 + 7;
vector<pair<int, int>> sub[M];
int c, n, m, d, q, w[M];
int dis[N][N];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++){
		int k; cin >> k;
		for(int j = 1; j <= k; j ++){
			int a, t; cin >> a >> t;
			sub[a].push_back({t, i});
		}
	}
	
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i ++) dis[i][i] = 0;
	for(int i = 1; i <= m; i ++){
		for(int u = 0; u < (int)sub[i].size(); u ++){
			for(int v = 0; v < (int)sub[i].size(); v ++){
				int U = sub[i][u].second, V = sub[i][v].second;
				int W = sub[i][u].first + sub[i][v].first;
				dis[U][V] = min(dis[U][V], W);
				dis[V][U] = min(dis[V][U], W);
			}
		}
	}
	
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while(q --){
		int st, ed, ans = 1e18; cin >> st >> ed;
		for(pair<int, int> sst: sub[st]){
			for(pair<int, int> sed: sub[ed]){
				ans = min(ans, w[st] + w[ed] + sst.first + sed.first + dis[sst.second][sed.second]);
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}

