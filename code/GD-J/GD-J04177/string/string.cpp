#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 5e5 + 100 ;
int n, l, r, s ;
int a[N] ;
char b[N] ;
int zzl_min (int x, int y) { return x < y ? x : y ; }
signed main ()
{
	freopen ("string.in", "r", stdin) ;
	freopen ("string.out", "w", stdout) ;
	ios :: sync_with_stdio (false) ;
	cin.tie (0), cout.tie (0) ;
	cin >> n ;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> b[i] ;
		if (b[i] == b[i - 1])
		{
			a[i - 1] += a[i] ;
			i -= 1, n -= 1 ;
		}
	}
	l = 1, r = n ;
	while (r > l)
	{
		if (b[l] != b[r])
		{
			s += zzl_min (a[r], a[l]) ;
		}
		if (a[r] > a[l]) a[r] -= a[l], l += 1 ;
		else if (a[l] > a[r]) a[l] -= a[r], r -= 1 ;
		else l += 1, r -= 1 ;
	}
	cout << s << endl ;
	return 0 ;
}
