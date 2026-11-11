#include <iostream>
#include <cstring>
using namespace std ;
const int N = 5e5 + 10 ;
const int M = 3e5+ 10 ;
int p[N] , t[N] , leave[M];
int main ()
{
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	int n, m ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n; i++)
	{
		cin >> p[i] ;
	}
	for (int i = 1 ; i <= n; i++)
	{
		memset(t,0 , sizeof(t)) ;
		int cur = 0 ;
		for (int j= i ; j<=n ; j++)
		{
			cur ++ ;
			t[cur] = p[j] ;
			if (j == i)
			{
				continue ;
			}
			int pos = 0 ;
			bool f = false ;
			for (int k = 1 ; k <= cur-1 ;k++)
			{
				if (t[k] == t[cur])
				{
					pos = k ;
					f= true ;
					break ;
				}
			}
			if (f)
			{
				for (int k = pos+1 ;k <= cur ;k ++)
				{
					t[k] = 0 ;
				}
				cur = pos ;
			}
		}
		for (int k = 1 ;k <= cur ;k ++)
		{
			leave[t[k]]++ ;
		}
	}
	for (int i =1 ; i <= m ; i++)
	{
		cout << leave[i] << " " ;
	}
	return 0 ;
}
