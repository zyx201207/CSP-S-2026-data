#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n , k;
ll a[N];
ll b[40];
ll bin[40];
bool flag[N];
ll ans = 0;


int main() {
    freopen( "and.in" , "r" , stdin );
    freopen( "and.out" , "w" , stdout );
    memset( flag , 0 , sizeof flag );
    cin >> n >> k;
    ll x = 1;
    bin[0] = 1;
    for ( int i = 1 ; i <= 35;  i ++ ){
        x *= 2;
        bin[i] = x;
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
        ll xx = a[i] , y = 0;
        while(xx) {
            b[y] += ( xx % 2 );
            xx /= 2;
            y ++;
        }
    }
    for ( int i = 31 ; i >= 0 ; i -- ) {
        if ( b[i] >= k ) {
            ans += bin[i];
            int cnt = 0;
            for ( int j = 1 ; j <= n ; j ++ ) {
                if ( flag[j] == true )
                    continue;
                if ( a[j] >= ans )
                    cnt ++;
            }
            if ( cnt < k ){
                ans -= bin[i];
            }
            else{
                for ( int j = 1 ; j <= n ; j ++ ) {
                    if ( a[j] < ans )
                        flag[j] = true;
                }
            }
        }
    }
    cout << ans << endl;
}
