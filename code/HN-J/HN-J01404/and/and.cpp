#include <bits/stdc++.h>
using namespace std ;

int main()
{
	freopen("and.in" , "r" , stdin) ; 
	freopen("and.out" , "w" , stdout) ;
	int n , m ;
	cin >> n >> m ;
	int a[n + 1] ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] ;
	}
	if(n <= 2000)
	{
		if(m == 1)
		{
			sort(a + 1 , a + n + 1) ;
			cout << a[n] ;
			return 0 ;
		}
		if(m == 2)
		{
			int cnt = 0 ;
			for(int i = 1 ; i <= n ; i ++)
			{
				for(int j = i + 1 ; j <= n ; j ++)
				{
					cnt = max(cnt , a[i] & a[j]) ;
				}
			}
			cout << cnt ;
			return 0 ;
		}
		if(m == n)
		{
			int cnt = a[1] ;
			for(int i = 2 ; i <= n ; i ++)
			{
				cnt = cnt & a[i] ;
			}
			cout << cnt ;
			return 0 ;
		}
	}
	sort(a + 1 , a + n + 1) ;
	cout << a[n - m + 1] ;
	return 0 ;
}

