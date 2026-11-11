#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
long long n, m;
long long a[ N ];
bool find ( int x ) {
    int sum = 0;
    for ( int i = 1; i <= x; i++ ) {
        sum += a[ x ] - a[ i ];
    }
    return sum <= m;
}
int main ( ) {
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    freopen( "crystal.in", "r", stdin );
    freopen( "crystal.out", "w", stdout );
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[ i ];
    }
    sort( a + 1, a + n + 1 );
    int l = 1, r = n;
    while ( l < r ) {
        int mid = ( l + r + 1 ) / 2;
        if( find ( mid ) ) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
