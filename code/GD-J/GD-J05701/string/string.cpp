#include <iostream>
#include <cmath>
using namespace std ;
const int N = 2e5 +10 ;
long long a[N] , pos[N];
char c[N] ;

int main ()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	int n ;
	cin>> n ;
	long long sum = 0 ;
	for (int i = 1 ;i <= n ;i++)
	{
		cin >> a[i] >> c[i];
		sum += a[i] ;	
		pos[i] = sum + 1 ;
	}
	bool flag = true ;
	for (int i = 1; i<= n ;i++)
	{
		if (a[i] != a[n-i+1])
		{
			flag = false ;
			break ;
		}
	}
	if (flag)
	{
		if (n % 2 == 0)
		{
			long long cnt = 0 ;
			for (int i = 1 ; i <= n / 2 ; i++)
			{
				if (c[i] != c[n - i + 1]) 
				{
					cnt +=  a[i];
				}
			}
			cout << cnt ;
			return 0 ;
		}
		else
		{
			long long cnt = 0 ;
			for (int i = 1 ; i <= floor(n/2) ; i++)
			{
				if (c[i] != c[n - i + 1]) 
				{
					cnt +=  a[i];
				}
			}
			cout << cnt ;
			return 0 ;
		}
	}
	else 
	{
		bool k = true ;
		for (int i= 1 ; i<= n-1 ; i++)
		{
			if (c[i] != c[i+1])
			{
				k = false ;
				break ;
			}
		}
		if (k)
		{
			cout << 0 ;
			return 0 ;
		}
		else
		{
			int cur = 1 , d = n ,ans = 0;
			long long l = 0 , k = 0 ;
			for (int i = 1 ; i <= floor(sum/2) ; i++)
			{
				if (i > a[cur]+l) 
				{
					l += a[cur] ;
					cur ++ ;
				}
				int p = sum - i + 1 ;
				if (p < sum-k - a[d] +1)
				{
					k += a[d] ;
					d-- ;
				} 
				if (c[cur] != c[d])
				{
					ans++ ;
				} 
			}
			cout << ans ;
			return 0 ;
		}
	}
	return 0 ;
}
