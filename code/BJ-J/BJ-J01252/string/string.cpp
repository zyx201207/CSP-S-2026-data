#include <cstdio>
#include <fstream>

const int N = 1e9 + 50;
char s[ N ];

int main( int argc, char *argv[] )
{
    freopen( "string.in", "r", stdin );
    freopen( "string.out", "w", stdout );
    int n{}, now = 1, sum{};
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i )
    {
        int a{};
        char c{};
        scanf( "%d", &a );
        getchar();
        scanf( "%c", &c );
        sum += a;
        for( int j = now; j < now + a; ++j )
            s[ j ] = c;
        now += a;
    }
    int mid{};
    if( sum % 2 == 1 )
        mid = sum + 1 >> 1;
    else
    {
        mid = sum >> 1;
        for( int i = sum + 1; i > mid; --i )
            s[ i ] = s[ i - 1 ];
        s[ mid + 1 ] = '#';
        ++sum;
    }
    int ans{};
    for( int i = 1, j = sum; i <= mid; ++i, --j )
    {
        if( s[ i ] != s[ j ] )
            ++ans;
    }
    printf( "%d\n", ans );

    return 0;
}
