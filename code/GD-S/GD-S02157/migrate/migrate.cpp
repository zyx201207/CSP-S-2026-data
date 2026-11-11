#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std ;

const int N = 5e3 + 5 ;

int Case, T, n, d, res, sum, a[N], dis[N], cnt[N] ;
vector<int> G[N] ;

/*
0 2
5 3
-2 -1 0 1 2
6 2 
-4 -3 -2 -1 3 6
*/

void dfs(int u, int dist)
{
	if (dis[u] > dist)
		dis[u] = dist, cnt[u] = 1 ;
	else if (dis[u] == dist)
		cnt[u] ++  ;
	if (u >= n)
		return ;
	for (auto v : G[u])
		dfs(v, dist + 1) ;
}

int main()
{
	freopen("migrate.in", "r", stdin) ;
	freopen("migrate.out", "w", stdout) ;
	ios::sync_with_stdio(false), cin.tie(0) ;
	
	cin >> Case >> T ;
	while (T -- )
	{
		res = 0, sum = 0 ;
		
		cin >> n >> d ;
		for (int i = 1 ; i <= n ; i ++ )
			cin >> a[i], G[i].clear() ;
		for (int i = 1 ; i <= n ; i ++ )
			for (int j = i + 1 ; j <= n ; j ++ )
				if (a[j] - a[i] <= d) G[i].push_back(j) ;
		for (int i = 1 ; i <= n ; i ++ )
		{
			memset(dis, 0x3f, sizeof dis) ;
			memset(cnt, 0, sizeof cnt) ;
			dfs(i, 0) ;
			for (int j = i + 1 ; j <= n ; j ++ )
				if (cnt[j] == 2) res ++  ;
		}
		cout << res << '\n' ;
	}
	
	return 0 ;
}
