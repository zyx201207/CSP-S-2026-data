#include <bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
il int rd(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = (s << 1) + (s << 3) + ch - 48;
	return s * w;
}
const int N = 500005, M = 505, INF = 1e18;
int cid, n, m, d, q, f[M][M], w[N];
vector <int> way[N], tim[N];
il void ckmin(int &x, int y){ x = (x < y ? x : y); }
signed main(){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cid = rd(), n = rd(), m = rd(), d = rd(), q = rd();
	for (int i = 1; i <= m; i++) w[i] = rd();
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = INF;
	for (int i = 1; i <= n; i++){
		int k = rd(); f[i][i] = 0;
		for (int j = 1; j <= k; j++){
			int x = rd(), t = rd();
			way[x].push_back(i), tim[x].push_back(t);
		}
	}
	for (int i = 1; i <= m; i++){
		int d = way[i].size();
		for (int j = 0; j < d; j++) for (int k = j + 1; k < d; k++)
			ckmin(f[way[i][j]][way[i][k]], tim[i][j] + tim[i][k]), ckmin(f[way[i][k]][way[i][j]], tim[i][j] + tim[i][k]);
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) ckmin(f[i][j], f[i][k] + f[k][j]);
	for (int u, v; q--;){
		u = rd(), v = rd();
		int du = way[u].size(), dv = way[v].size(), ans = INF;
		for (int i = 0; i < du; i++) for (int j = 0; j < dv; j++) ckmin(ans, f[way[u][i]][way[v][j]] + tim[u][i] + tim[v][j]);
		ans += w[u] + w[v];
		printf ("%lld\n", ans);
	}
	return 0;
}

