#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
long long c , t;
long long a[N];
long long n , d;
long long jump[N];
long long jump2[N];
long long flag;
long long cnt = 1;

void solve() {
    long long ans = 0;
    cin >> n >> d;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
    }
    for ( int i = 1 ; i < n ; i ++ ) {
        long long l = i , r = n;
        if ( ( a[n] - a[i] ) <= d ){
            jump[i] = n;
            continue;
        }
        while( l <= r ) {
            long long mid = ( l + r ) / 2;
            if ( ( a[mid] - a[i] ) <= d ) {
                l = mid + 1;
                jump[i] = mid;
            }
            else
                r = mid - 1;
        }
    }
    jump2[1] = 1;
    for ( int i = n ; i > 1 ; i -- ) {
        long long l = 1 , r = i;
        if ( ( a[i] - a[1] ) <= d ) {
            jump2[i] = 1;
            continue;
        }
        while( l <= r ) {
            long long mid = ( l + r ) / 2;
            if ( ( a[i] - mid ) <= d ) {
                r = mid - 1;
                jump2[i] = mid;
            }
            else
                l = mid + 1;
        }
    }
    for ( int i = 1 ; i < n - 1 ; i ++ ) {
        for ( int j = i + 2 ; j <= n ; j ++ ) {
            long long x = 0;
            long long l = i , r = j;
            while( l < r ) {
                l = jump[l];
                x ++;
            }
            cnt = 1;
            long long L[x + 1] , R[x + 1];
            l = i ,r = j;
            L[0] = i;
            R[x] = j;
            L[x] = j;
            R[0] = i;
            long long len = x;
            x = 0;
            while( l < r ) {
                l = jump[l];
                x ++;
                if ( l < r )
                    L[x] = l;
                else
                    break;
            }
            l = i , r = j;
            while( l < r ) {
                r = jump2[r];
                x --;
                if ( l < r )
                    R[x] = r;
                else
                    break;
            }
            long long ct = 0;
            for ( int k = 1 ; k < len ; k ++ ) {
                if ( ( L[k] - R[k] ) > 1 ) {
                    ct = 3;
                }
                else if ( ( L[k] - R[k] ) == 1 )
                    ct ++;
            }
            if ( ct == 1 )
                ans ++;
        }
    }
    cout << ans << endl;
}

int main() {
    freopen( "migrate.in" , "r" , stdin );
    freopen( "migrate.out" , "w" , stdout );
    cin >> c >> t;
    while( t -- )
        solve();
}
