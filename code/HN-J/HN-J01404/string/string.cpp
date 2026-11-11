#include <bits/stdc++.h>
using namespace std ;
string s ;
int main()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	int n ;
	cin >> n ;
	int a[n + 1] ;
	char c[n + 1] ;
	long long cnt = 0 ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] >> c[i] ;
	}
	int i = 1 , j = n ;
	while(1)
	{
		if(i >= j)
		{
			cout << cnt ;
			return 0 ;
		}
		if(a[i] < a[j])
		{
			if(c[i] != c[j])
			{
				cnt += a[i] ;
			}
			a[j] -= a[i] ;
			i ++ ;
			continue ;
		}
		if(a[i] == a[j])
		{
			if(c[i] != c[j])
			{
				cnt += a[i] ;
			}
			i ++ ;
			j -- ;	
			continue ;	
		}
		if(a[i] > a[j])
		{
			if(c[i] != c[j])
			{
				cnt += a[j] ;
			}
			a[i] -= a[j] ;
			j -- ;
			continue ;
		}
	}
	return 0 ;
}

