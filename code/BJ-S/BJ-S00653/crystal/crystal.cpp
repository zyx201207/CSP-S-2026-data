#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n , m;
ll a[N];

bool check( int x ) {
    ll k = a[x];
    ll cnt = 0;
    for ( int i = 1 ; i <= x ; i ++ ) {
        cnt = cnt + ( k - a[i] );
    }
    if ( cnt > m )
        return false;
    return true;
}

int main() {
    freopen( "crystal.in" , "r" , stdin );
    freopen( "crystal.out" , "w" , stdout );
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i ++ )         cin >> a[i];
    sort( a + 1 , a + 1 + n );
    ll l = 1 , r = n;
    ll ans = 0;
    while( l <= r ) {
        ll mid = ( l + r ) / 2;
        if ( check(mid) ) {
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
}
