#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 500005;
int w[M], k[N], a[N][M], dis[N][N], t[N][M];
int main()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << dis[x][y];
	}
	return 0;
}
