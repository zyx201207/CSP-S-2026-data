#include <bits/stdc++.h>
using namespace std;
#define rint register int
const int N = 2e5 + 5;
int c , t;
int n , k;
vector < int > e[ N ];
int u[ N ] , v[ N ];
namespace sub1
{
  const int N = 5000 + 5;
  int p , q;
  int dep[ N ] , w[ N ]; 
  void dfs ( int x , int fa )
  {
    dep[ x ] = 0;
    for ( auto y : e[ x ] ) if ( y ^ fa )
      dfs ( y , x ) , dep[ x ] = max ( dep[ y ] + 1 , dep[ x ] );
  }
  int rt1 , rt2;
  void get ( int x , int fa , int & rt )
  {
    // cerr << x << ' ' << dep[ x ] << ' ' << w[ x ] << '\n';
    if ( max ( w[ x ] , dep[ x ] ) < dep[ rt ] ) rt = x;
    int mx , se; mx = se = -1;
    for ( auto y : e[ x ] ) if ( y ^ fa )
      if ( mx < dep[ y ] ) se = mx , mx = dep[ y ];
      else if ( se < dep[ y ] ) se = dep[ y ];
    for ( auto y : e[ x ] ) if ( y ^ fa )
    {
      w[ y ] = max ( w[ x ] , ( mx == dep[ y ] ? se : mx ) + 1 ) + 1;
      get ( y , x , rt );
    }
    // w[ x ] = w[ x ] 
  }
  void rev ( int x , int fa )
  {
    dep[ x ] = 0;
    for ( auto y : e[ x ] ) if ( y != fa && ( ( x != p && x != q ) || ( y != p && y != q ) ) )
      rev ( y , x ) , dep[ x ] = max ( dep[ y ] + 1 , dep[ x ] );
  }
  queue < int > g[ N ];
  bool vis[ N ];
  int mx = 0;
  void add ( int x )
  {
    for ( auto y : e[ x ] ) if ( ! vis[ y ] && ( ( x != p && x != q ) || ( y != p && y != q ) ) )
      g[ dep[ y ] + 1 ]. push ( y );
  }
  int solve ()
  {
    dep[ 0 ] = 1e9;
    int ans = n;
    for ( rint i = 1 ; i < n ; i ++ )
    {
      p = u[ i ] , q = v[ i ];
      dfs ( p , q ) , dfs ( q , p );
      rt1 = rt2 = 0;
      w[ p ] = w[ q ] = 0;
      get ( p , q , rt1 );
      get ( q , p , rt2 );  
      rev ( rt1 , 0 ) , rev ( rt2 , 0 );
      int mx = 0;
      for ( rint j = 0 ; j <= n ; j ++ )
      {
        vis[ j ] = 0;
        while ( g[ j ]. size () ) g[ j ]. pop ();
      } 
      vis[ rt1 ] = vis[ rt2 ] = 1;
      add ( rt1 ); add ( rt2 ); 
      mx = n; int z = k;
      while ( mx )
      {
        if ( ! g[ mx ]. size () ) { mx --; continue; }
        if ( ! z ) break;
        z --;
        int x = g[ mx ]. front (); g[ mx ]. pop ();
        add ( x );
      }
      ans = min ( ans , mx );
    }
    return ans;
  }
}
namespace sub2
{
  int f[ N ][ 2 ] , w[ N ];
  int ans = 1e9;
  void dfs ( int x , int fa )
  {
    f[ x ][ 0 ] = f[ x ][ 1 ] = 0;
    w[ x ] = 0;
    for ( auto y : e[ x ] ) if ( y ^ fa )
    {
      dfs ( y , x );
      w[ x ] = max ( w[ x ] , w[ y ] );
      if ( f[ x ][ 0 ] < f[ y ][ 0 ] + 1 ) f[ x ][ 1 ] = f[ x ][ 0 ] , f[ x ][ 0 ] = f[ y ][ 0 ] + 1;
      else if ( f[ x ][ 1 ] < f[ y ][ 0 ] + 1 ) f[ x ][ 1 ] = f[ y ][ 0 ] + 1;
    }
    w[ x ] = max ( w[ x ] , f[ x ][ 0 ] + f[ x ][ 1 ] );
  }
  void get ( int x , int fa , int fal , int val )
  {
    ans = min ( ans , max ( ( w[ x ] + 1 ) >> 1 , ( max ( val , fal ) + 1 ) >> 1 ) );
    int fi , se , mfi , mse; fi = se = 0 , mfi = mse = 0;
    for ( auto y : e[ x ] ) if ( y ^ fa )
      if ( fi < f[ y ][ 0 ] + 1 ) se = fi , fi = f[ y ][ 0 ] + 1;
      else if ( se < f[ y ][ 0 ] + 1 ) se = f[ y ][ 0 ] + 1;
    for ( auto y : e[ x ] ) if ( y ^ fa )
      if ( mfi < w[ y ] ) mse = mfi , mfi = w[ y ];
      else if ( mse < w[ y ] ) mse = w[ y ];
    for ( auto y : e[ x ] ) if ( y ^ fa )
      get ( y , x , max ( fal + 1 , ( f[ y ][ 0 ] + 1 == fi ? se : fi ) ) , max ( { val , fal + ( f[ y ][ 0 ] + 1 == fi ? se : fi ) , ( mfi == w[ y ] ? mse : mfi ) } ) );
  }
  int solve ()
  {
    ans = 1e9;
    dfs ( 1 , 0 );
    get ( 1 , 0 , 0 , 0 );
    return ans;
  }
}
namespace sub3
{
  const int N = 1e5 + 5;
  int p , q;
  int dep[ N ] , w[ N ]; 
  void dfs ( int x , int fa )
  {
    dep[ x ] = 0;
    for ( auto y : e[ x ] ) if ( y ^ fa )
      dfs ( y , x ) , dep[ x ] = max ( dep[ y ] + 1 , dep[ x ] );
  }
  int rt1 , rt2;
  void get ( int x , int fa , int & rt )
  {
    // cerr << x << ' ' << dep[ x ] << ' ' << w[ x ] << '\n';
    if ( max ( w[ x ] , dep[ x ] ) < dep[ rt ] ) rt = x;
    int mx , se; mx = se = -1;
    for ( auto y : e[ x ] ) if ( y ^ fa )
      if ( mx < dep[ y ] ) se = mx , mx = dep[ y ];
      else if ( se < dep[ y ] ) se = dep[ y ];
    for ( auto y : e[ x ] ) if ( y ^ fa )
    {
      w[ y ] = max ( w[ x ] , ( mx == dep[ y ] ? se : mx ) + 1 ) + 1;
      get ( y , x , rt );
    }
    // w[ x ] = w[ x ] 
  }
  void rev ( int x , int fa )
  {
    dep[ x ] = 0;
    for ( auto y : e[ x ] ) if ( y != fa && ( ( x != p && x != q ) || ( y != p && y != q ) ) )
      rev ( y , x ) , dep[ x ] = max ( dep[ y ] + 1 , dep[ x ] );
  }
  queue < int > g[ N ];
  bool vis[ N ];
  int mx = 0;
  void add ( int x )
  {
    for ( auto y : e[ x ] ) if ( ! vis[ y ] && ( ( x != p && x != q ) || ( y != p && y != q ) ) )
      g[ dep[ y ] + 1 ]. push ( y );
  }
  int solve ()
  {
    dep[ 0 ] = 1e9;
    int ans = n , z = n >> 2;
    for ( rint i = max ( z - 10 , 1 ) ; i < n && i <= z + 10 ; i ++ )
    {
      p = u[ i ] , q = v[ i ];
      dfs ( p , q ) , dfs ( q , p );
      rt1 = rt2 = 0;
      w[ p ] = w[ q ] = 0;
      get ( p , q , rt1 );
      get ( q , p , rt2 );  
      rev ( rt1 , 0 ) , rev ( rt2 , 0 );
      int mx = 0;
      for ( rint j = 0 ; j <= n ; j ++ )
      {
        vis[ j ] = 0;
        while ( g[ j ]. size () ) g[ j ]. pop ();
      } 
      vis[ rt1 ] = vis[ rt2 ] = 1;
      add ( rt1 ); add ( rt2 ); 
      mx = n; int z = k;
      while ( mx )
      {
        if ( ! g[ mx ]. size () ) { mx --; continue; }
        if ( ! z ) break;
        z --;
        int x = g[ mx ]. front (); g[ mx ]. pop ();
        add ( x );
      }
      ans = min ( ans , mx );
    }
    return ans;
  }
}
namespace sub4
{
  mt19937 rnd ( time ( 0 ) );
  const int N = 1e6 + 5;
  int p , q;
  int dep[ N ] , w[ N ]; 
  void dfs ( int x , int fa )
  {
    dep[ x ] = 0;
    for ( auto y : e[ x ] ) if ( y ^ fa )
      dfs ( y , x ) , dep[ x ] = max ( dep[ y ] + 1 , dep[ x ] );
  }
  int rt1 , rt2;
  void get ( int x , int fa , int & rt )
  {
    // cerr << x << ' ' << dep[ x ] << ' ' << w[ x ] << '\n';
    if ( max ( w[ x ] , dep[ x ] ) < dep[ rt ] ) rt = x;
    int mx , se; mx = se = -1;
    for ( auto y : e[ x ] ) if ( y ^ fa )
      if ( mx < dep[ y ] ) se = mx , mx = dep[ y ];
      else if ( se < dep[ y ] ) se = dep[ y ];
    for ( auto y : e[ x ] ) if ( y ^ fa )
    {
      w[ y ] = max ( w[ x ] , ( mx == dep[ y ] ? se : mx ) + 1 ) + 1;
      get ( y , x , rt );
    }
    // w[ x ] = w[ x ] 
  }
  void rev ( int x , int fa )
  {
    dep[ x ] = 0;
    for ( auto y : e[ x ] ) if ( y != fa && ( ( x != p && x != q ) || ( y != p && y != q ) ) )
      rev ( y , x ) , dep[ x ] = max ( dep[ y ] + 1 , dep[ x ] );
  }
  queue < int > g[ N ];
  bool vis[ N ];
  int mx = 0;
  void add ( int x )
  {
    for ( auto y : e[ x ] ) if ( ! vis[ y ] && ( ( x != p && x != q ) || ( y != p && y != q ) ) )
      g[ dep[ y ] + 1 ]. push ( y );
  }
  int solve ()
  {
    dep[ 0 ] = 1e9;
    int ans = n;
    for ( rint t = 0 ; t < 100 ; t ++ )
    {
      int i = rnd () % ( n - 1 ) + 1;
      p = u[ i ] , q = v[ i ];
      dfs ( p , q ) , dfs ( q , p );
      rt1 = rt2 = 0;
      w[ p ] = w[ q ] = 0;
      get ( p , q , rt1 );
      get ( q , p , rt2 );  
      rev ( rt1 , 0 ) , rev ( rt2 , 0 );
      int mx = 0;
      for ( rint j = 0 ; j <= n ; j ++ )  
      {
        vis[ j ] = 0;
        while ( g[ j ]. size () ) g[ j ]. pop ();
      } 
      vis[ rt1 ] = vis[ rt2 ] = 1;
      add ( rt1 ); add ( rt2 ); 
      mx = n; int z = k;
      while ( mx )
      {
        if ( ! g[ mx ]. size () ) { mx --; continue; }
        if ( ! z ) break;
        z --;
        int x = g[ mx ]. front (); g[ mx ]. pop ();
        add ( x );
      }
      ans = min ( ans , mx );
    }
    return ans;
  }
}
void solve ()
{
  cin >> n >> k; 
  for ( rint i = 1 ; i <= n ; i ++ )
    e[ i ]. clear ();
  k -= 2;
  for ( rint i = 1 ; i < n ; i ++ )
  {
    cin >> u[ i ] >> v[ i ];
    e[ u[ i ] ]. push_back ( v[ i ] );
    e[ v[ i ] ]. push_back ( u[ i ] );
  }
  if ( c <= 10 )
    return cout << sub1 :: solve () << '\n' , void ();
  if ( c == 11 || c == 12 )
    return cout << sub2 :: solve () << '\n' , void ();
  if ( c == 13 || c == 14 )
    return cout << sub3 :: solve () << '\n' , void ();
  if ( c > 14 ) 
    return cout << sub4 :: solve () << '\n' , void ();
}
signed main ()
{
  freopen ( "hub.in" , "r" , stdin );
  freopen ( "hub.out" , "w" , stdout );
  ios :: sync_with_stdio ( 0 ); cin. tie ( 0 ) , cout. tie ( 0 );
  cin >> c >> t;
  while ( t -- )
    solve ();
  return 0;
}