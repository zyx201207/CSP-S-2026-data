#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 9e3 + 457;
ll c, n, m, d, q, w[M], cnt, dist[M][M];
bool vis[500501];
vector <int> edge[500501];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
		cin >> w[i];
	for (int i = 1; i <= m + m; i ++)
		for (int j = 1; j <= m + m; j ++)
			dist[i][j] = INT_MAX;
	for(int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			int a, t;
			cin >> a >> t;
			dist[i][m + a] = dist[m + a][i] = min(dist[i][m + a], w[a] + t);
		}
	}
	for (int k = 1; k <= m + m; k ++)
		for (int i = 1; i <= m + m; i ++)
			for (int j = 1; j <= m + m; j ++)
				if (k > m)
					dist[i][j] = min(dist[i][k] + dist[k][j] - w[k - m] * 2, dist[i][j]);
				else
					dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
	while (q --) {
		int x, y;
		cin >> x >> y;
		cout << dist[m + x][m + y] << '\n';
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

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
