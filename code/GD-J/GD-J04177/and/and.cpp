#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 5e5 + 100 ;
int n, m, l, ss, s ;
int a[N], jl[N][40] ;
bool vis[N] ;
signed main ()
{
	freopen ("and.in", "r", stdin) ;
	freopen ("and.out", "w", stdout) ;
	ios :: sync_with_stdio (false) ;
	cin.tie (0), cout.tie (0) ;
	cin >> n >> m ;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i] ;
		l = 0 ;
		while (a[i] != 0)
		{
			jl[i][++ l] = a[i] % 2 ;
			a[i] /= 2 ;
		}
	}
	for (int i = 33; i >= 1; i --)
	{
		ss = 0 ;
		for (int j = 1; j <= n; j ++)
			if (jl[j][i] != 0 && vis[j] == 0)
				ss += 1 ;
		if (ss < m) continue ;
		for (int j = 1; j <= n; j ++)
			if (jl[j][i] == 0 && vis[j] == 0)
				vis[j] = 1 ;
		s += (1 << (i - 1)) ;
	}
	cout << s << endl ;
	return 0 ;
}
