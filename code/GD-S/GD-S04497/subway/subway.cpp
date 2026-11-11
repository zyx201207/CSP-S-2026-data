#include <bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
const int MAXN = 5e2 + 10, MAXM = 5e5 + 10;
const ll INF = 1e18;
int T, n, m;
int w[MAXN];
ll f[MAXN][MAXN];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &T, &n, &m, &T, &T);
	for ( int i = 1; i <= m; i++ )
	{
		scanf("%d", &w[i]);
		for ( int j = 1; j <= m; j++ )
		{
			f[i][j] = INF;
		}
	}
	for ( int len, i = 1; i <= n; i++ )
	{
		vector<int> a, t;
		cin >> len;
		for ( int j = 1; j <= len; j++ )
		{
			ll x, y;
			cin >> x >> y;
			for ( int k = 0; k < a.size(); k++ )
			{
				f[x][a[k]] = min(f[x][a[k]], y + t[k]);
				f[a[k]][x] = min(f[a[k]][x], y + t[k]);
			}
			a.push_back(x);
			t.push_back(y);
		}
	}
	for ( int i = 1; i <= m; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			if ( i == j )
			{
				continue;
			}
			for ( int k = 1; k <= m; k++ )
			{
				if ( i == k || j == k )
				{
					continue;
				}
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for ( int x, y; T--; )
	{
		scanf("%d%d", &x, &y);
		printf("%lld\n", f[x][y] + w[x] + w[y]);
	}
//	cout << "\ndebug:\n";
//	for ( int i = 1; i <= m; i++ )
//	{
//		for ( int j = 1; j <= m; j++ )
//		{
//			if ( f[i][j] == INF )
//			{
//				cout << "# ";
//			}
//			else
//			{
//				cout << f[i][j] << ' ';
//			}
//		}
//		cout << endl;
//	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
