#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int n;
ll a[N];
char c[N];
ll len = 0;

int main() {
    freopen( "string.in" , "r" , stdin );
    freopen( "string.out" , "w" , stdout );
    cin >> n;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i] >> c[i];
        len += a[i];
    }
    len ++;
    ll mid = len / 2;
    ll l = 1 , r = len - 1;
    ll li = 1 , ri = n;
    ll ans = 0;
    while( l <= r ) {
        if ( c[li] != c[ri] ) {
            ans += min( a[li] , a[ri] );
        }
        if ( a[li] > a[ri] ) {
            a[li] -= a[ri];
            l += a[ri];
            r -= a[ri];
            ri --;
        }
        else if ( a[li] == a[ri] ) {
            l += a[ri];
            r -= a[ri];
            li ++;
            ri --;
        }
        else{
            a[ri] -= a[li];
            l += a[li];
            r -= a[li];
            li ++;
        }
    }
    cout << ans << endl;
}
