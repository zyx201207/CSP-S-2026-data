#include <cstdio>
#include <fstream>

const int N = 5e5 + 50, M = 3e5 + 50;
int cnt[ M ], q[ N ], num[ N ];
bool vis[ M ];

int main( int argc, char *argv[] )
{
    freopen( "card.in", "r", stdin );
    freopen( "card.out", "w", stdout );
    int n{}, m{};
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= n; ++i )
        scanf( "%d", &num[ i ] );
    for( int j = 1; j <= n; ++j )
    {
        int p = 1;
        for( int i = j; i <= n; ++i )
        {
            int a = num[ i ];
            if( !vis[ a ] )
            {
                q[ p ] = a;
                ++p;
                vis[ a ] = true;
            }
            else
            {
                --p;
                while( p >= 1 && q[ p ] != a )
                {
                    vis[ q[ p ] ] = false;
                    --p;
                }
                ++p;
            }
        }
        for( int i = 1; i <= p; ++i )
            ++cnt[ q[ i ] ];
        for( int i = 1; i <= m; ++i )
            vis[ i ] = false;
        for( int i = 1; i <= p; ++i )
            q[ i ] = 0;
    }
    for( int i = 1; i <= m; ++i )
        printf( "%d ", cnt[ i ] );
    printf( "\n" );

    return 0;
}
