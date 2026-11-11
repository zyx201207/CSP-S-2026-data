#include <iostream>
using namespace std;
int n , m , a[500005] , ans[300005] , sum[300005] , k = 1 , b;
bool f( int a )
{
	b = k ;
	b -= 1 ;
	for( int i = 1 ; i <= b ; i ++ )
	{
		if( a == sum[i] )
		{
			k = i;
			return 1 ;
		}
	}
	return 0;
}
int main()
{
	freopen("problem1.in","r",stdin);
	freopen("problem1.out","w",stdout);
	cin >> n >> m ;
	for ( int i =1 ; i <= n ; i ++ )
	{
		cin >> a[i];
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		for ( int j = i ; j <= n ; j ++ )
		{
			if ( k >= 2 && f(a[j]) )
			{
			    sum[k] = a[j];
			  	k ++ ;
				continue ;
			}
			sum[k] = a[j] ;
			k ++ ;
		}
		k --; 
		for( int j = 1 ; j <= k ; j ++ )
		{
			ans[sum[j]] ++ ;
		}
		k = 1;
	}
	for ( int i = 1 ; i <= m ; i ++ )
	{
		cout << ans[i] << " " ;
	}
}
// It's so easy. 
// CCF isn't different at all.
