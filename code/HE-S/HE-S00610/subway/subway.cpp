#include <iostream> 
#include <cstring>
#include <vector>
#define int long long
using namespace std;

const int MXM = 5e5 + 5;
const int MXN = 505;
struct Pair{int v, t;};

int c, n, m, d, q, w[MXM], k[MXN];
int dis[MXN][MXN]; 
vector<Pair> G[MXM];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 0; i < MXN; i += 1) dis[i][i] = 0;
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i += 1) cin >> w[i];
	for (int i = 1; i <= n; i += 1){
		cin >> k[i];
		for (int j = 1, a, t; j <= k[i]; j += 1){
			cin >> a >> t;
			G[a].push_back((Pair){i, t});
		}
	}
	
	for (int i = 1; i <= m; i += 1){
		for (Pair p1 : G[i]) for (Pair p2 : G[i]){
			int u = p1.v, v = p2.v;
			dis[u][v] = min(dis[u][v], p1.t + p2.t);
		}
	}
	for (int k = 1; k <= n; k += 1)
		for (int i = 1; i <= n; i += 1)
			for (int j = 1; j <= n; j += 1)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	while (q--){
		int u, v, ans = 0x3f3f3f3f3f3f3f3f;
		cin >> u >> v;
		for (Pair p1 : G[u]) for (Pair p2 : G[v]){
			int l1 = p1.v, l2 = p2.v;
			ans = min(ans, p1.t + p2.t + dis[l1][l2]);
		}
		cout << ans + w[u] + w[v] << '\n';
	}
	
	return 0;
} 












