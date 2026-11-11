#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

const int N = 500 + 5, M = 5e5 + 5;
const int mod = 998244353;
const int inf = 4e18;

int zh, n, m, d, q;
int w[M], dis[N][N];
vector<pii> vec[M];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> zh >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		int k; cin >> k;
		for (int j = 1, a, t; j <= k; j++) cin >> a >> t, vec[a].pb({i, t});
	}
	mem(dis, 0x3f);
	for (int i = 1; i <= m; i++){
		for (int j = 0; j < (int)vec[i].size(); j++){
			for (int k = j + 1; k < (int)vec[i].size(); k++){
				int u = vec[i][j].fir, v = vec[i][k].fir, w1 = vec[i][j].sec, w2 = vec[i][k].sec; 
				dis[u][v] = min(dis[u][v], w1 + w2);
				dis[v][u] = min(dis[v][u], w1 + w2);
			}
		}
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	while (q--){
		int x, y; cin >> x >> y;
		int ans = inf;
		for (auto it1 : vec[x]){
			for (auto it2 : vec[y]) ans = min(ans, dis[it1.fir][it2.fir] + it1.sec + it2.sec + w[x] + w[y]);
		}
		cout << ans << "\n";
	}
	return 0;
}
