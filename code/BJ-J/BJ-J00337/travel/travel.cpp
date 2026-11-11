#include <bits/stdc++.h>
using namespace std;
string c1, c2;
int n, m;
string s1, s2;
int cases1, lie1;
int cases2, lie2;
int main ( ) {
    freopen( "travel.in", "r", stdin );
    freopen( "travel.out", "w", stdout );
    cin >> c1;
    cin >> s1;
    n = ( c1[ 0 ] -'0' ) * 10 + ( c1[ 1 ] - '0' );
    cases1 = s1[ 2 ] - 'A' + 1;
    lie1 = ( s1[ 0 ] - '0' ) * 10 + ( s1[ 1 ] - '0' );
    cin >> c2;
    cin >> s2;
    m = ( c2[ 0 ] -'0' ) * 10 + ( c2[ 1 ] - '0' );
    cases2 = s2[ 2 ] - 'A' + 1;
    lie2 = ( s2[ 0 ] - '0' ) * 10 + ( s2[ 1 ] - '0' );
    //cout << n << " " << m << endl;
    //cout << cases1 << " " << cases2 << endl;
    //cout << lie1 << " " << lie2 << endl;
    if ( n != m ) {
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    cout << 1 << ( lie1 == lie2 ? 1 : 0 );
    if ( cases1 <= 3 && cases2 <= 3 ) {
        cout << ( lie1 == lie2 ? 1 : 0 ) << ( lie1 == lie2 && ( cases1 - cases2 == 1 || cases1 - cases2 == -1 ) ? 1 : 0 );
    } else if ( cases2 > 3 && cases1 > 3 ) {
        cout << ( lie1 == lie2 ? 1 : 0 ) << ( lie1 == lie2 ? 1 : 0 );
    } else {
        cout << 0 << 0;
    }
    return 0;
}
