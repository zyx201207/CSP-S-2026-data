#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5, M = 5e5 + 5;
int c, n, m, d, q, x, y, k, w[M], a[N][M], t[N][M];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++) cin >> a[i][j] >> t[i][j];
	}
	while (q--)
	{
		cin >> x >> y;
		cout << w[x] + w[y] + t[x][x] + t[x][y] << "\n";
	}
	return 0;
}
