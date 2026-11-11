#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 6e5 + 100 ;
int n, m, l, dq, ma ;
int a[N] ;
int zzl_max (int x, int y)
{
	return x > y ? x : y ;
}
signed main () 
{
	freopen ("crystal.in", "r", stdin) ;
	freopen ("crystal.out", "w", stdout) ;
	ios :: sync_with_stdio (false) ;
	cin.tie (0), cout.tie (0) ;
	cin >> n >> m ;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i] ;
	}
	sort (a + 1, a + n + 1) ;
	l = n ;
	for (int i = n - 1; i >= 1; i --)
	{
		dq += (a[n] - a[i]) ;
		if (dq > m)
		{
			dq -= (a[n] - a[i]) ;
			break ;
		}
		l = i ;
	}
//	cout << l << endl ;
	ma = zzl_max (ma, n - l + 1) ;
	for (int i = n - 1; i >= 1; i --)
	{
		dq -= (a[i + 1] - a[i]) * (i - l + 1) ;
		for (int j = l - 1; j >= 1; j --)
		{
			dq += (a[i] - a[j]) ;
			if (dq > m)
			{
				dq -= (a[i] - a[j]) ;
				break ;
			}
			l = j ;
		}
//		if (i == 3)
//			cout << l << endl ;
		ma = max (ma, i - l + 1) ;
	}
	cout << ma << endl ;
	return 0 ;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
