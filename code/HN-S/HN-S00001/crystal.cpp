#include <bits/stdc++.h>
using namespace std;
#define rint register int
const int N = 5e5 + 5;
#define int long long
int n , m , a[ N ];
int s[ N ];
signed main ()
{
  freopen ( "crystal.in" , "r" , stdin );
  freopen ( "crystal.out" , "w" , stdout );
  ios :: sync_with_stdio ( 0 ); cin. tie ( 0 ) , cout. tie ( 0 );
  cin >> n >> m ;
  for ( rint i = 1 ; i <= n ; i ++ )  
    cin >> a[ i ];
  sort ( a + 1 , a + n + 1 );
  for ( rint i = 1 ; i <= n ; i ++ )
    s[ i ] = s[ i - 1 ] + a[ i ];
  int ans = 0;
  for ( rint i = 1 ; i <= n ; i ++ )
  {
    int l , r , mid , res; l = 1 , r = i , res = i;
    while ( l <= r )
    {
      mid = l + r >> 1;
      if ( a[ i ] * ( i - mid + 1 ) - ( s[ i ] - s[ mid - 1 ] ) <= m ) r = mid - 1 , res = mid;
      else l = mid + 1;
    }
    ans = max ( ans , i - res + 1 );
  }
  cout << ans << '\n';
  return 0;
}