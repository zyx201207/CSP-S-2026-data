#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define int long long

using namespace std ;

const int N = 5e5 + 5, M = 5e2 + 5, INF = 0x3f3f3f3f3f3f3f3f ;

int Case, n, m, d, quest, W[N] ;
vector<pair<int, int>> G[M + N] ;
int f[M][M] ;

inline void uadd(int u, int v, int w)
{
	G[u].push_back({v, w}) ;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
------
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

signed main()
{
	freopen("subway.in", "r", stdin) ;
	freopen("subway.out", "w", stdout) ;
	memset(f, 0x3f, sizeof (f)) ;
	ios::sync_with_stdio(false), cin.tie(0) ;
	
	cin >> Case >> n >> m >> d >> quest ;
	for (int i = 1 ; i <= m ;  ++ i)
		cin >> W[i] ;
	for (int i = 1, ai, ti, k ; i <= n ;  ++ i)
	{
		cin >> k, f[i][i] = 0 ;
		for (int j = 1 ; j <= k ;  ++ j)
			cin >> ai >> ti, uadd(ai, i, ti) ;
	}
	for (int k = 1 ; k <= m ;  ++ k)
		for (auto u : G[k]) for (auto v : G[k])
			f[u.first][v.first] = min(f[u.first][v.first], u.second + v.second) ;
	for (int k = 1 ; k <= n ;  ++ k)
		for (int u = 1 ; u <= n ;  ++ u)
			for (int v = 1 ; v <= n ;  ++ v)
				f[u][v] = min(f[u][v], f[u][k] + f[k][v]) ;
	while (quest -- )
	{
		int u, v, mid = INF ;
		cin >> u >> v ;
		for (auto i : G[u])
			for (auto j : G[v])
				mid = min(mid, i.second + j.second + f[i.first][j.first]) ;
		cout << W[u] + W[v] + mid << '\n' ;
	}
	
	return 0 ;
}
