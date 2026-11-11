#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 5e6 + 100 ;
int op, t, n, m, l, s ;
long long x ;
int a[N], b[N] ;
int dis[N], jl[N] ;
vector<int> e[N] ;
priority_queue<pair<int,int>> q ;
bool vis[N] ;
signed main ()
{
	freopen ("migrate.in", "r", stdin) ;
	freopen ("migrate.out", "w", stdout) ;
	ios :: sync_with_stdio (false) ;
	cin.tie (0), cout.tie (0) ;
	cin >> op >> t ;
	while (t --)
	{
		s = 0 ;
		cin >> n >> m ;
		for (int i = 1; i <= n; i ++)
		{
			cin >> x ;
			a[i] = x ;
			e[i].clear () ;
		}
//		for(int i = 1; i <= n; i ++)
//			cout << a[i] - a[i - 1] << " " ;
		l = 1 ;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = l; j <= n; j ++)
			{
				if (a[j] - a[i] > m) break ;
				l = j ;
			}
			b[i] = l ;
		}
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= b[i]; j ++)
			{
				e[i].push_back (j) ;
				e[j].push_back (i) ;
//				cout << i << " " << j << endl;
			}
		for (int ii = 1; ii <= n; ii ++)
		{
			for (int i = 1; i <= n; i ++)
				dis[i] = LLONG_MAX / 2, vis[i] = 0, jl[i] = 0 ;
			dis[ii] = 0 ;
			jl[ii] = 1 ;
			q.push ({0, ii}) ;
			while (! q.empty ())
			{
				int u = q.top ().second ;
				q.pop () ;
				if (vis[u] == 1) continue ;
				vis[u] = 1 ;
				for (int i = 0; i < e[u].size(); i ++)
				{
					int v = e[u][i] ;
					if (dis[v] > dis[u] + 1)
					{
						dis[v] = dis[u] + 1, jl[v] = 1 ;
						q.push ({-dis[v], v}) ;
					}
					else if (dis[v] == dis[u] + 1) jl[v] += jl[u] ;
				}
			}
			for (int i = 1; i <= n; i ++)
			{
				if (jl[i] == 2) s += 1 ;
//				cout << dis[i] << " " ;
			}
//			if (ii == 1) cout << dis[5] << endl ;
//			cout << jl[4] << endl ;
//			cout << endl ;
		}
		cout << s / 2 << endl ;
	}
	return 0 ;
}
/*
0 1
5 2
1 2 3 4 5

0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896
 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

0 1
4 2
1 2 3 4

0 1
5 3
-2 -1 0 1 2

0 1
6 2
-4 -3 -2 -1 3 6
*/
