#include <bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 100 ;
struct E
{
	int nxt, to, w ;
} e[N * 2] ;
int head[N], cn ;
int n, m ;
int a[N], sz[N], s[N] ;
int mp[N], mp1[N] ;
void add (int x, int y, int z)
{
	e[++ cn].nxt = head[x] ;
	e[cn].to = y ;
	e[cn].w = z ;
	head[x] = cn ;
}
void dfs (int x)
{
	sz[x] = 1 ;
	for (int i = head[x]; i; i = e[i].nxt)
	{
		dfs (e[i].to) ;
		s[e[i].w] += sz[e[i].to] ;
		sz[x] += sz[e[i].to] ;
	}
}
signed main ()
{
	freopen ("card.in", "r", stdin) ;
	freopen ("card.out", "w", stdout) ;
	ios :: sync_with_stdio (false) ;
	cin.tie (0), cout.tie (0) ;
	cin >> n >> m ;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i] ;
		mp1[a[i]] = i ;
		mp[a[i]] += 1 ;
	}
	for (int i = 1; i <= n; i ++)
	{
		add (mp1[a[i]] + 1, i, a[i]) ;
//		cout << mp1[a[i]] + 1 << " " << i << " " << a[i] << endl ;
	}
		
	dfs (n + 1) ;
	for (int i = 1; i <= m; i ++)
		cout << s[i] << " " ;
	return 0 ;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
