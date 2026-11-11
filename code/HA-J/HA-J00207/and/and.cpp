#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 10 , E = 35 ;
int n , m , a [N] , res , zuigao ;
vector <int> v , tmp ;
bool yes [N] [E] ;

bool takee (int x , int m) // 返回 x 的第 m 位 （从右往左数 
{
	return (x >> (m - 1)) & 1 ;
}

int main ()
{
	freopen ("and.in" , "r" , stdin) ;
	freopen ("and.out" , "w" , stdout) ;
	ios :: sync_with_stdio (0) ;
	cin . tie (0) ;
	cout . tie (0) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i ++)
		cin >> a [i] ;
	for (int i = 1 ; i <= n ; i ++)
	{
		for (int j = 1 ; j <= 31 ; j ++)
			yes [i] [j] = takee (a [i] , j) ;
	}
//	for (int i = 1 ; i <= n ; i ++)
//	{
//		for (int j = 31 ; j >= 1 ; j --)
//			cout << yes [i] [j] ;
//		cout << "\n" ;
//	}
	for (int i = 31 ; i >= 1 ; i --)
	{
		bool flag = false ;
		for (int j = 1 ; j <= n ; j ++)
			if (yes [j] [i] == 1)
			{
				zuigao = i ;
				flag = true ;
				break ;
			}
		if (flag)
			break ;
	}
	for (int i = zuigao ; i >= 1 ; i --)
	{
		tmp . clear () ;
		if (v . empty ())
		{
			for (int j = 1 ; j <= n ; j ++)
				if (yes [j] [i] == 1)
					tmp . push_back (j) ;
		}
		else
			for (auto j : v)
				if (yes [j] [i] == 1)
					tmp . push_back (j) ;
		if (tmp . size () >= m)
		{
			v . clear () ;
			for (auto j : tmp)
				v . push_back (j) ;
//			for (auto j : v)
//				cout << j << " " ;
//			cout << "\n" ;
			res += (1 << (i - 1)) ;
		}
	}
	cout << res ;
	return 0 ;
}
/*
4 2
3 15 12 12
*/
