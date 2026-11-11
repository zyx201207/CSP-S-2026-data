#include <bits/stdc++.h>
using namespace std;
int c , t;
int main (){
    freopen( "migrate.in" , "r" , stdin );
    freopen( "migrate.out" , "w" , stdout );
    cin >> c >> t;
    for( int x = 1; x <= t; x ++ ){
        long long n , d;
        cin >> n >> d;
        int dp[2000005] = { 0 };
        int mi[2000005];
        for( int i = 1; i <= n; i ++ ){
            cin >> mi[i];
        }
        for( int i = 1; i <= n; i ++ ){
            if( i != 1 ){
                dp[i] = 1;
            }else{
                for( int j = 1; j <= i; j ++ ){
                    if( mi[i] - mi[j] <= d ){
                            dp[i] = 1;
                        for( int k = j; k <= i; k ++ ){
                            dp[k] = min( dp[i] , dp[j] + 1 );
                        }
                    }else{
                        dp[j] = 0;
                    }
                }
            }
        }
    }
    return 0;
}
