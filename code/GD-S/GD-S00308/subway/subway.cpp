#include<bits/stdc++.h>
using namespace std;
const int INF = 1e18;
const int N = 1e6 + 5;
const int M = 5e2 + 5;
vector<pair<int, int> > vc[N];
int w[M][M], t[M][M], dis[M][M], k[N], a[N], c, n, m, d, q, ans;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> w[i][j] >> t[i][j];
			vc[w[i][j]].push_back({i, t[i][j]});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j < vc[i].size(); j++)
			for(int k = 0; k < vc[i].size(); k++)
				if(j != k) dis[vc[i][j].first][vc[i][k].first] = min(dis[vc[i][j].first][vc[i][k].first], vc[i][j].second + vc[i][k].second);
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--){
		int x, y;
		cin >> x >> y;
		ans = INF;
		for(int i = 0; i < vc[x].size(); i++)
			for(int j = 0; j < vc[y].size(); j++)
				ans = min(ans, vc[x][i].second + vc[y][j].second + dis[vc[x][i].first][vc[y][j].first]);
		cout << ans + a[x] + a[y] << endl;
	}
	return 0;
}
