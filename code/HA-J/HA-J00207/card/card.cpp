#include <bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 10 , M = 3e5 + 10 ; 
int n , m , a [N] , res [N] ;
int c [N] , cnt ;
bool b [N] ;

void solve (int x)
{
	memset (b , false , sizeof (b)) ;
	memset (c , 0 , sizeof (c)) ;
	cnt = 0 ;
	for (int i = x ; i <= n ; i ++)
	{
		if (b [a [i]])
			for (int j = cnt ; j >= 0 ; j --)
				if (c [j] == a [i])
				{
					cnt = j - 1 ;
					break ;
				}
		c [++ cnt] = a [i] ;
		b [a [i]] = true ;
	}
	for (int i = 1 ; i <= cnt ; i ++)
		res [c [i]] ++ ;
}

int main ()
{
	freopen ("card.in" , "r" , stdin) ;
	freopen ("card.out" , "w" , stdout) ;
	ios :: sync_with_stdio (0) ;
	cin . tie (0) ;
	cout . tie (0) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i ++)
		cin >> a [i] ;
	for (int i = 1 ; i <= n ; i ++)
	{
		solve (i) ;
	}
	for (int i = 1 ; i <= m ; i ++)
		cout << res [i] << " " ;
	return 0 ;
}
