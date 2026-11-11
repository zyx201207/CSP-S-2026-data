#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 100000 + 5;
int c, n, m, d, q;
int w[N], a[501][N], t[501][N];
int main ()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++) cin >> a[i][j] >> t[i][j];
	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		cout << w[x] + t[1][x] + t[2][3] + t[3][4] + t[4][5] + w[y] + t[x][y] << endl;
	}
	return 0;
}
