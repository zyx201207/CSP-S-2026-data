#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 9;
struct node {
    int nu;
    int many;
};
int n, m, sum;
int l, r;
int f = 1;
node a[ N ];
signed main ( ) {
    freopen( "string.in", "r", stdin );
    freopen( "string.out", "w", stdout );
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        char c;
        int j;
        cin >> j >> c;
        a[ i ].nu = c - 'a' + 1;
        a[ i ].many = j;
        if ( a[ i ].nu != a[ i - 1 ].nu && i != 1 ) {
            f = 0;
        }
    }
    if ( f ) {
        cout << 0 << endl;
        return 0;
    }
    l = 1; r = n;
    while ( l <= r ) {
        if ( a[ l ].nu != a[ r ].nu ) {
            if ( a[ l ].many < a[ r ].many ) {
                sum += a[ l ].many;
                a[ r ].many -= a[ l ].many;
                l++;
            } else if ( a[ l ].many > a[ r ].many ) {
                sum += a[ r ].many;
                a[ l ].many -= a[ r ].many;
                r--;
            } else {
                sum += a[ l ].many;
                l++;
                r--;
            }
        } else {
            if ( a[ l ].many < a[ r ].many ) {
                a[ r ].many -= a[ l ].many;
                l++;
            } else if ( a[ l ].many > a[ r ].many ) {
                a[ l ].many -= a[ r ].many;
                r--;
            } else {
                l++;
                r--;
            }
        }
    }
    cout << sum;
    return 0;
}
