#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define ll long long
const int N = 5e5 + 5 , M = 500 + 5;
vector < pair < int , int > > e[ N ];
ll f[ M ][ M ];
int c , n , m , d , q;
int w[ N ];
signed main ()
{
  freopen ( "subway.in" , "r" , stdin );
  freopen ( "subway.out" , "w" , stdout );
  ios :: sync_with_stdio ( 0 ); cin. tie ( 0 ) , cout. tie ( 0 );
  cin >> c >> n >> m >> d >> q;
  for ( rint i = 1 ; i <= m ; i ++ )
    cin >> w[ i ];
  for ( rint i = 1 , k ; i <= n ; i ++ )
  {
    cin >> k;
    for ( rint j = 1 ; j <= k ; j ++ )
    {
      int u , v; cin >> u >> v;
      e[ u ]. push_back ( { i , v } );
    }
  }
  memset ( f , 0x3f , sizeof f );
  for ( rint i = 1 ; i <= n ; i ++ ) f[ i ][ i ] = 0;
  for ( rint i = 1 ; i <= m ; i ++ )
  {
    for ( rint j = 0 ; j < e[ i ]. size () ; j ++ )
    {
      int u = e[ i ][ j ]. first , w1 = e[ i ][ j ]. second;
      for ( rint k = j + 1 ; k < e[ i ]. size () ; k ++ )
      {
        int v = e[ i ][ k ]. first , w2 = e[ i ][ k ]. second;
        f[ u ][ v ] = f[ v ][ u ] = min ( f[ u ][ v ] , ( ll ) w1 + w2 );
      }
    }
  }
  for ( rint k = 1 ; k <= n ; k ++ )
    for ( rint i = 1 ; i <= n ; i ++ )
      for ( rint j = 1 ; j <= n ; j ++ )
        f[ i ][ j ] = min ( f[ i ][ j ] , f[ i ][ k ] + f[ k ][ j ] );
  while ( q -- )
  {
    int u , v; cin >> u >> v;
    ll ans = 1e18;
    for ( rint i = 0 ; i < e[ u ]. size () ; i ++ )
    {
      for ( rint j = 0 ; j < e[ v ]. size () ; j ++ )
      {
        ans = min ( ans , f[ e[ u ][ i ]. first ][ e[ v ][ j ]. first ] + e[ u ][ i ]. second + e[ v ][ j ]. second );
      }
    }
    cout << ans + w[ u ] + w[ v ] << '\n';
  }
  return 0;
}