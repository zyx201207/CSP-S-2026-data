#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 505;
int c, n, m, d, q;
int w[N], k[N], b[N];
int a[M][M], t[M][M];

int main()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= 2k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--)
	{
		memset (b, 0, sizeof b);
		int x, y, ans = 0, idx = 0;
		cin >> x >> y;
		ans += w[x] + w[y];
		int now = x;
		while (now != y)
		{
			int minn = INT_MAX;
			for (int i = 1; i <= n; i++)
			{
				if (a[i][now] != 0)
				{
					minn = min (minn, t[i][now]);
				}
			}
			ans += minn;
			for (int i = 1; i <= n; i++)
			{
				if (t[i][now] == minn)
				{
					now = i;
				}
			} 
		}
		cout << ans << '\n';
	}

	return 0;
}

