#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int rd() {
	int x = 0; char ch = getchar();
	while (ch < 48 || ch > 57) ch = getchar();
	while (ch > 47 && ch < 58) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar(); 
	}
	return x;
}
const int M = 5e5 + 10;
const int N = 510;
const int INF = 1e18;
int Tid, n, m, d, q;
int w[M];
int dis[N][N];
vector < pair <int, int> > rt[M];
signed main() {
//	system("fc subway.out subway7.ans");
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	Tid = rd(), n = rd(), m = rd(), d = rd(), q = rd();
	for (int i = 1; i <= m; i++) w[i] = rd();
	for (int r = 1, k; r <= n; r++) {
		k = rd();
		for (int j = 1, u, v; j <= k; j++) {
			u = rd(), v = rd();
			rt[u].push_back(make_pair(r, v));
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int u = 1; u <= m; u++) {
		for (int i = 0; i < rt[u].size(); i++) {
			int r1 = rt[u][i].first, v1 = rt[u][i].second;
			for (int j = 0; j < rt[u].size(); j++) {
				int r2 = rt[u][j].first, v2 = rt[u][j].second;
				dis[r1][r2] = min(dis[r1][r2], v1 + v2);
				dis[r2][r1] = dis[r1][r2];
			}
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int x, y, ans = dis[0][0];
		x = rd(), y = rd();
		for (int i = 0; i < (int)rt[x].size(); i++) {
			int r1 = rt[x][i].first, v1 = rt[x][i].second;
			for (int j = 0; j < (int)rt[y].size(); j++) {
				int r2 = rt[y][j].first, v2 = rt[y][j].second;
				ans = min(ans, dis[r1][r2] + v1 + v2);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
}
