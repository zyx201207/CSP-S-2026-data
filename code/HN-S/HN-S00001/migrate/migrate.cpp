#include <bits/stdc++.h>
using namespace std;
#define rint register int
const int N = 2e6 + 5;
#define int long long
int c , t , n , d;
int x[ N ];
int f[ N ][ 2 ][ 2 ];
int to[ N ];
void solve ()
{
  int ans = 0;
  cin >> n >> d;
  for ( rint i = 1 ; i <= n ; i ++ )
    cin >> x[ i ];
  for ( rint i = 1 ; i <= n ; i ++ )
    for ( rint j = 0 ; j < 2 ; j ++ )
      for ( rint k = 0 ; k < 2 ; k ++ )
        f[ i ][ j ][ k ] = 0; 
  for ( rint i = n , j = n ; i >= 1 ; i -- )
  {
    while ( x[ j ] - x[ i ] > d ) j --;
    to[ i ] = j;
  }
  for ( rint i = 1 ; i <= n ; i ++ ) 
    f[ to[ i ] ][ 0 ][ 0 ] ++;
  x[ 0 ] = -8e18;
  for ( rint i = 1 ; i <= n ; i ++ ) if ( to[ i ] != i )
  {
    if ( i == 1 || x[ to[ i ] ] - x[ i - 2 ] > d ) f[ to[ i ] ][ x[ to[ i ] ] - x[ i - 1 ] <= d ][ x[ to[ i ] - 1 ] - x[ i - 1 ] <= d ] += f[ i ][ 0 ][ 0 ];
    if ( x[ to[ i ] ] - x[ i - 1 ] > d ) f[ to[ i ] ][ 0 ][ x[ to[ i ] - 1 ] - x[ i - 1 ] <= d ] += f[ i ][ 0 ][ 1 ];
    if ( x[ to[ i ] ] - x[ i - 1 ] > d ) 
      f[ to[ i ] ][ 1 ][ x[ to[ i ] - 1 ] - x[ i - 1 ] <= d ] += f[ i ][ 1 ][ 0 ] + f[ i ][ 1 ][ 1 ];
    if ( i != 1 ) ans += 1ll * max ( 0ll , min ( to[ i ] - 1 , to[ i - 1 ] ) - max ( i , to[ i - 2 ] ) ) * f[ i ][ 0 ][ 0 ];
    ans += 1ll * max ( 0ll , to[ i ] - 1 - to[ i - 1 ] ) * ( f[ i ][ 1 ][ 0 ] + f[ i ][ 1 ][ 1 ] );
    ans += f[ i ][ 1 ][ 0 ] + f[ i ][ 1 ][ 1 ];
  }
  else
    ans += f[ i ][ 1 ][ 0 ] + f[ i ][ 1 ][ 1 ];
  cout << ans << '\n';
}
signed main ()
{
  freopen ( "migrate.in" , "r" , stdin );
  freopen ( "migrate.out" , "w" , stdout );
  ios :: sync_with_stdio ( 0 ); cin. tie ( 0 ) , cout. tie ( 0 );
  cin >> c >> t;
  while ( t -- )
    solve ();
  return 0;
}