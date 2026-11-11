#include <bits/stdc++.h>
using namespace std ;

const int N = 5005 ;

int main ()
{
	freopen ("migrate.in" , "r" , stdin) ;
	freopen ("migrate.out" , "w" , stdout) ;
	ios :: sync_with_stdio (0) ;
	cin . tie (0) ;
	cout . tie (0) ;
	int n , m , q ;
	cin >> q ;
	cin >> q ;
	while (q --)
	{
		cin >> n >> m ;
		int x ;
		for (int i = 1 ; i <= n ; i ++)
			cin >> x ;
		cout << n - m - 1 << "\n" ;
	}
	return 0 ;
}

