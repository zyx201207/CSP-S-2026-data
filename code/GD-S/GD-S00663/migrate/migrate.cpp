#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5005;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N, D, ans;
int x[MAXN], sum[MAXN], dp[MAXN][MAXN];// dp[i][j] 表示到 st -> i 的时候走 j 步方案数
void slove(){
    cin >> N >> D;
    // cout << N << " " << D << endl;
    for( int i = 1; i <= N; i ++ ){
        cin >> x[i];
        // sum[i] = sum[i - 1] + x[i];
    }
    for( int st = 1; st <= N; st ++ ){
        for( int i = 1; i <= N; i ++ ){
            for( int j = 1; j <= N; j ++ )
                dp[i][j] = 0;
        }
        dp[st][0] = 1;
        for( int i = st + 1; i <= N; i ++ ){
            int d = ( i - st + D - 1 ) / D;
            for( int j = st; j < i; j ++ ){
                // int dd = ( j - st + D - 1 ) / D;
                dp[i][d] += dp[j][d - 1];
                // cerr << st << " " << j << " " << i << " " << d << " " << dp[j][d - 1] << "\n";
            }
            // for( int j = i + 1; j <= N && x[j] - x[i] <= D; j ++ ){
                // dp[i + D] += dp[i];
            // cerr << st << " " << i << " " << i + D << " " << dp[i] << "\n";
                // cerr << st << " " << i << " " << j << " " << dp[j] << "\n";
            // }
        }
        // cerr << "\n";
        for( int i = st + 1; i <= N; i ++ ){
            // cerr << i << " " << ( i - st + D - 1 ) / D << " " << dp[i][( i - st + D - 1 ) / D] << "\n";
            if( dp[i][( i - st + D - 1 ) / D] == 2 ){
                // cerr << st << " " << i << "\n";
                ans ++;
            }
        }
        // for( int i = 1; i <= N; i ++ ) cout << dp[i] << " ";
        // cout << "\n";
        // int tot = 0;
        // for( int i = N; i > N - D; i -- ){
        //     tot += dp[i];
        // }
        // if( tot == 2 ) ans ++;
        // for( int i = st + 1; i <= N; i ++ ){
        // cerr << N / 2 << " " << dp[( N - st + D - 1 ) / D] << "\n";
        //     if( dp[( N - st + D - 1 ) / D] == 2 ) ans ++;
        // }
    }
    cout << ans << "\n";
    ans = 0;
    return;
}

signed main(){
    ios::sync_with_stdio( 0 );
    cin.tie( 0 ), cout.tie( 0 );
    freopen( "migrate.in", "r", stdin );
    freopen( "migrate.out", "w", stdout );
    int C, T = 1;
    cin >> C;
    cin >> T;
    while( T -- )
        slove();
    return 0;
}