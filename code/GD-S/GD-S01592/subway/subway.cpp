#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 505, M = 500005;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[M], k[N];
vector<pair<int, int>> dis[M];
long long d_l[N][N];
void solve(){
	int x, y;
	cin >> x >> y;
	long long ans = inf;
	for (int i = 0; i < dis[x].size(); ++i){
		for (int j = 0; j < dis[y].size(); ++j){
			long long now = dis[x][i].se + dis[y][j].se;
			now += d_l[dis[x][i].fi][dis[y][j].fi];
			ans = min(ans, now);
		}
	}
	ans += w[x] + w[y];
	cout << ans << "\n"; 
	return;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i){
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j){
			int aa, tt;
			cin >> aa >> tt;
			dis[aa].push_back({i, tt});
		}
	}
	memset(d_l, 0x3f, sizeof(d_l));
	for (int i = 1; i <= m; ++i){
		for (int j = 0; j < dis[i].size(); ++j){
			auto n1 = dis[i][j];
			for (int k = j + 1; k < dis[i].size(); ++k){
				auto n2 = dis[i][k];
				d_l[n1.fi][n2.fi] = min(d_l[n1.fi][n2.fi], (long long)n1.se + n2.se);
				d_l[n2.fi][n1.fi] = d_l[n1.fi][n2.fi];
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		d_l[i][i] = 0;
	}
	for(int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				d_l[i][j] = min(d_l[i][j], d_l[i][k] + d_l[k][j]);
			}
		}
	}
	while(q--){
		solve();
	}
	
	return 0;
}

