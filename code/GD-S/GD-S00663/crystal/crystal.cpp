#include<bits/stdc++.h>
#define int long long
// 14:47 exp: 100 pts.  Oct31==Dec25?
using namespace std;
const int MAXN = 5e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M;
int a[MAXN];
void slove(){
    cin >> N >> M;
    for( int i = 1; i <= N; i ++ ){
        cin >> a[i];
    }
    sort( a + 1, a + N + 1 );
    int l = 1, now = 0, ans = 0;
    for( int i = 2; i <= N; i ++ ){
        int j = a[i] - a[i - 1];
        now += j * ( i - l );
        while( now > M ){
            now -= a[i] - a[l];
            l ++;
        }
        ans = max( ans, i - l + 1 );
    }
    cout << ans;
    return;
}

signed main(){
    ios::sync_with_stdio( 0 );
    cin.tie( 0 ), cout.tie( 0 );
    freopen( "crystal.in", "r", stdin );
    freopen( "crystal.out", "w", stdout );
    int T = 1;
    // cin >> T;
    while( T -- )
        slove();
    return 0;
}