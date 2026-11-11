#include <cstdio>
#include <algorithm>
#include <fstream>
#include <cmath>
#define ll long long

const int N = 5e5 + 50;
ll a[ N ], d[ N ];
ll max( ll x, ll y )
{
    if( x > y )
        return x;
    return y;
}
ll abs( ll x )
{
    if( x > 0 )
        return x;
    return -x;
}

int main( int argc, char *argv[] )
{
    freopen( "crystal.in", "r", stdin );
    freopen( "crystal.out", "w", stdout );
    ll n{}, m{};
    scanf( "%lld%lld", &n, &m );
    if( n <= 2e5 + 5e4 )
    {
        for( int i = 1; i <= n; ++i )
            scanf( "%lld", &a[ i ] );
        std::sort( a + 1, a + n + 1 );
        for( int i = 2; i <= n; ++i )
            d[ i ] = a[ i ] - a[ i - 1 ];
        ll ans = -1;
        for( int i = 1, j = i + 1; i <= n; ++i, j = i + 1 )
        {
            int tmp{};
            while( j <= n && tmp <= m )
            {
                tmp = tmp + ( j - i ) * d[ j ];
                ++j;
            }
            ans = max( ans, j - i - 1 );
        }
        printf( "%lld\n", ans );

        return 0;
    }
    ll x{}, y{};
    scanf( "%lld%lld", &x, &y );
    ll z = abs( x - y );
    if( z == 1 )
    {
        ll C = sqrt( 1 + m * 4 );
        ll k = ( C + 1 ) / 2;
        printf( "%lld\n", k + 1 );
        return 0;
    }
    ll C = sqrt( 1 + m * 8 / z );
    ll hi = ( C + 1 ) / 2;
    printf( "%lld\n", hi );
    return 0;
}
