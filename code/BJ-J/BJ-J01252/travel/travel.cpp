#include <cstdio>
#include <fstream>

int abs( int x )
{
    if( x < 0 )
        return -x;
    return x;
}
int main( int argc, char *argv[] )
{
    freopen( "travel.in", "r", stdin );
    freopen( "travel.out", "w", stdout );
    int c1{}, c2{};
    char s1[ 4 ], s2[ 4 ];
    scanf( "%d", &c1 );
    getchar();
    for( int i = 1; i <= 3; ++i )
        s1[ i ] = getchar();
    scanf( "%d", &c2 );
    getchar();
    for( int i = 1; i <= 3; ++i )
        s2[ i ] = getchar();
    bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
    if( c1 == c2 )
        flag1 = true;
    printf( "%d", (int)flag1 );
    if( flag1 && s1[ 1 ] == s2[ 1 ] && s1[ 2 ] == s2[ 2 ] )
        flag2 = true;
    printf( "%d", (int)flag2 );
    if( flag2 && ( ( s1[ 3 ] <= 'C' && s2[ 3 ] <= 'C' ) || ( s1[ 3 ] >= 'D' && s2[ 3 ] >= 'D' ) ) )
        flag3 = true;
    printf( "%d", (int)flag3 );
    if( flag3 && ( abs( (int)s1[ 3 ] - s2[ 3 ] ) == 1 || ( s1[ 3 ] == 'D' && s2[ 3 ] == 'F' ) || ( s1[ 3 ] == 'F' && s2[ 3 ] == 'D' ) ) )
        flag4 = true;
    printf( "%d\n", (int)flag4 );

    return 0;
}
