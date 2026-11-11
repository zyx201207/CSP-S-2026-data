#include<bits/stdc++.h>
using namespace std ;
int n ;
long long a ;
string s ;
char c[5201314] ;
long long ans ;
long long k ;
long long m ;
bool tp (  )
{
	for ( int i = 1 ; i < n ; i++ )
	{
		if ( c[i] != c[i + 1] )
		{
			return 0 ;
		}
	}
	return 1 ;
}
int main ()
{
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	cin >> n ;
//	scanf ( "%d",&n ) ;
	for ( int i = 1 ; i <= n ; i++ )
	{
//		scanf ( "%lld%lld",&a,&c[i] ) ;
		cin >> a >> c[i] ;
		for ( int j = 1 ; j <= a ; j++ )
		{
			s += c[i] ;
		}
		k += a ;
	}  
	if ( n <= 1 )
	{
		cout << 0 ;
		return 0 ;
	}
	if ( tp () )
	{
		cout << 0 ;
		return 0 ;
	}
	if ( k & 1 == 0 )
	{
		m = k / 2 ;
		for ( int i = m + 1 , j = m ; i <= k , j >= 1 ; i++ , j-- )
		{
			if ( s[i] != s[j] )
			{
				ans++ ;
				s[i] = s[j] ;
			}
		 } 
//		 printf ( "%lld",ans ) ;
		 cout << ans ;
	}
	else
	{
		m = k / 2 ;
		for ( int i = m + 2 , j = m ; i <= k , j >= 1 ; i++ , j-- )
		{
			if ( s[i] != s[j] )
			{
				ans++ ;
				s[i] = s[j] ;
			}
		}
		cout << ans ;
//		printf( "%lld",ans ) ;
	}
}
