#include <bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 10 ;
long long n , m , a [N] , res , diff [N] , sum [N] ;

int main ()
{
	freopen ("crystal.in" , "r" , stdin) ;
	freopen ("crystal.out" , "w" , stdout) ;
	ios :: sync_with_stdio (0) ;
	cin . tie (0) ;
	cout . tie (0) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i ++)
		cin >> a [i] ;
	sort (a + 1 , a + n + 1) ;
	for (int i = 1 ; i <= n ; i ++)
		diff [i] = a [i] - a [i - 1] ;
//	sort (diff + 1 , diff + n + 1) ;
	for (int i = 1 ; i <= n ; i ++)
		sum [i] = sum [i - 1] + diff [i] ;
	long long tmp = 0 ;
//	for (int i = 1 ; i <= n ; i ++)
//		cout << diff [i] << " " ;
//	cout << "\n" ;
	for (long long l = 1 , r = 1 ; r <= n ; r ++)
	{
		tmp += diff [r] * (r - l) ;
		if (abs (tmp) > m)
		{
			while (abs (tmp) > m)
				tmp -= sum [r] - sum [l] , l ++ ;
		}
//		cout << l << " " << r << " " << r - l + 1 << " " << tmp << endl ;
		res = max (res , r - l + 1) ;
	}
	cout << res ;
	return 0 ;
}

