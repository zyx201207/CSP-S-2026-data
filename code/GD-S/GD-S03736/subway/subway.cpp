#include <bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 100 ;
const int inf = INT_MAX / 2 ;
int op, n, m, d, qq, x, y ;
int a[N], l[N] ;
vector <int> e[N] ;
vector <int> w[N] ;
int q[N * 2] ;
vector <pair<int, int>> pp[N] ;
int vis[N] ;
int zzl_min (int x, int y) { return x < y ? x : y ; }
void solve1 ()
{
	const int M = 5005 ;
	int f[M][M] ;
	for (int i = 0; i < 5000; i ++)
		for (int j = 0; j < 5000; j ++)
			f[i][j] = inf ;
	for (int i = 1; i <= m; i ++) f[i][i] = 0 ;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < l[i]; j ++)
			for (int k = j + 1; k < l[i]; k ++)
				f[e[i][j]][e[i][k]] = zzl_min (f[e[i][j]][e[i][k]], w[i][j] + w[i][k]) ;
	for (int  i = 1; i <= m; i ++)
		for (int j = 1; j <= m; j ++)
			for (int k = 1; k <= m; k ++)
			{
				if (i == j || j == k || i == k) continue ;
				if (f[i][j] != inf && f[j][k] != inf)
					f[i][k] = zzl_min (f[i][k], f[i][j] + f[j][k]) ;
			}
				
	for (int i = 1; i <= qq; i ++)
	{
		cin >> x >> y ;
		cout << f[x][y] + a[x] + a[y] << endl ;
	}
}
signed main ()
{
	freopen ("subway.in", "r", stdin) ;
	freopen ("subway.out", "w", stdout) ;
	cin >> op >> n >> m >> d >> qq ;
	for (int i = 1; i <= m; i ++)
	{
		cin >> a[i] ;
	}
	for (int i = 1; i <= n; i ++)
	{
		cin >> l[i] ;
		for (int j = 0; j < l[i]; j ++)
		{
			cin >> x >> y ;
			e[i].push_back (x) ;
			w[i].push_back (y) ;
			pp[x].push_back({i, j}) ;
		}
	}
	if (op >= 12 && op <= 15)
	{
//		cout << qq << endl ;
//cout << 
		for (int i1 = 1; i1 <= qq; i1 ++)
		{
			cin >> x >> y ;
//			cout << x << " " << y << " " << qq << endl ;
			int h = 0, t = 0, ii , jj ;
			q[++ t] = x ;
			for (int i = 1; i <= m; i ++) vis[i] = -1 ;
			vis[x] = 0 ;
			int kk = 0 ;
			while (h < t)
			{
				h += 1 ;
		//		if (q[h] == 3) cout << vis[3] << endl ;
				int ll = pp[q[h]].size () ;
				for (int i = 0; i < ll; i ++)
				{
					ii = pp[q[h]][i].first, jj = pp[q[h]][i].second ;
					for (int j = jj + 1; j < l[ii]; j ++)
					{
						if (vis[e[ii][j]] != -1) continue ;
						vis[e[ii][j]] = vis[q[h]] + 1 ;
						q[++ t] = e[ii][j] ;
						if (e[ii][j] == y) { kk = vis[y] * w[1][0] * 2 ; break ; }
						/*
		12 2 5 20 1
		1 1 1 1 1
		4 1 2 2 2 3 2 4 2
		2 3 2 5 2
		1 5
						*/
					}
					if (kk != 0) break ;
				}
				if (kk != 0) break ;
			}
			cout << a[x] + a[y] + kk << endl ;
		}
		return 0 ;
	}
	solve1 () ;
	return 0 ;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
