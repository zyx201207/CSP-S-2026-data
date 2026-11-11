#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10;
const int M = 5e6 + 10;
const int INF = 1e9 + 7;
int c, T, n, d, ans, x[M], dis[N][N], f[N][N];
inline int read()
{
	int x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch))
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--)
	{
		n = read(), d = read();
		for (int i = 1; i <= n; ++i) x[i] = read();
		if (n <= 500)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					dis[i][j] = INF;
					f[i][j] = 0;
				}
				dis[i][i] = 0;
				f[i][i] = 1;
			}
			for (int i = 1; i <= n; ++i)
			{
				for (int j = i + 1; j <= n; ++j)
				{
					if (x[j] - x[i] > d) break;
					dis[i][j] = 1;
					f[i][j] = 1;
				}
			}
			for (int k = 1; k <= n; ++k)
			{
				for (int i = 1; i <= n; ++i)
				{
					for (int j = 1; j <= n; ++j)
					{
						if (i == j || j == k || i == k) continue;
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
				}
			}
			for (int k = 1; k <= n; ++k)
			{
				for (int i = 1; i < k; ++i)
				{
					for (int j = k + 1; j <= n; ++j)
					{
						if (dis[i][j] == dis[i][k] + dis[k][j])
							f[i][j] += (f[i][k] * f[k][j]);
					}
				}
			}
			ans = 0;
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					if (f[i][j] == 2) ++ans;
				}
			}
			cout << ans << endl;
		}
		else
		{
			int D = x[2] - x[1];
			if (D > d) cout << 0 << endl;
			else
			{
				int to = D / d;
				int toto = to * 2 - 1;
				cout << n - toto + 1 << endl;
			}
		}
	}
	return 0;
}

//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
