#include<bits/stdc++.h>
using namespace std ;
int n , m ;
long long a[200100] ;
long long ans = 1 ;
int cmp ( int x , int y )
{
	return x > y ;
}
int main ()
{
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ )
	{
//		scanf ( "%lld",&a[i] ) ;
	cin >> a[i] ; 
	}
	
	sort ( a + 1 , a + 1 + n , cmp ) ;
	ans = a[1] ;
	for ( int i = 2 ; i <= m ; i++ )
	{
		ans &= a[i] ;
	}   
	   cout << ans ;
//	printf ( "%lld",ans ) ; 
}
