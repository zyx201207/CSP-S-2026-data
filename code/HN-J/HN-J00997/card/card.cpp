#include<bits/stdc++.h>
using namespace std ;
int n , m ;
int a[5201314] ;
int f[5201314] ;
long long ans ;
int anss[5201314] ;
int main ()
{
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
//	scanf ( "%d",&n,m ) ;
	cin >> n >> m ;
	memset ( a , -1 , sizeof ( a ) ) ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> a[i] ;
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
		for ( int j = i ; j <= n ; j++ )
		{
			if ( f[j] == 0 )
			{
				f[j] = 1 ;
			}
			else
			{
				for ( int z = j + 1 ; z <= n ; z++ )
				{
					a[z] = -1 ;
				}
			}
		}
		for ( int j = 1 ; j <= n ; j++ )
		{
			if ( a[j] >= 0 )
			anss[a[j]]++ ;
		}
	}  
	for ( int i = 1 ; i <= m ; i++ )
	{
		cout << anss[i] << ' ' ;
	}
}
