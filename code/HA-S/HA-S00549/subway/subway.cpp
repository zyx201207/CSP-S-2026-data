#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500 + 5, M = 5e5 + 5;
const ll inf = 1e18;

int c, n, m, d, q;
ll dist[N][N], w[M];

struct fn{
	int id, t;
};
vector<fn> v[M];

void init(){
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= m; i++){
		for (int j = 0; j < v[i].size(); j++){
			for (int k = j + 1; k < v[i].size(); k++){
				int x = v[i][j].id, y = v[i][k].id;
				dist[x][y] = min(dist[x][y], (ll)v[i][j].t + v[i][k].t);
				dist[y][x] = min(dist[y][x], (ll)v[i][j].t + v[i][k].t);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		int k; cin >> k;
		for (int j = 1; j <= k; j++){
			int x, t; cin >> x >> t;
			v[x].push_back({i, t});
		}
	}
	
	init();
	
	while (q--){
		int x, y; cin >> x >> y;
		ll ans = inf;
		for (int i = 0; i < v[x].size(); i++){
			for (int j = 0; j < v[y].size(); j++){
				ans = min(ans, (ll)v[x][i].t + v[y][j].t + dist[v[x][i].id][v[y][j].id]);
			}
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	
	return 0;
}
