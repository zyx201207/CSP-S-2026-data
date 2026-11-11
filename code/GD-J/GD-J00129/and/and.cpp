#include <bits/stdc++.h>
using namespace std ;
const int maxn = 2 * 1e5 + 10 ;
long long n , m , a[maxn] , dp[maxn] ;
int main ( ) {

    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;

    cin >> n >> m; 
    for (int i = 1 ;i <= n ; i++) 
        {cin >> a[i] ; dp[i] = a[i] ; }

    for (int i = 2; i <= m ; i++) {
        for (int j = n ; j >= i ; j--) {

            dp[j] = (a[j] & dp[j-1]) ;
            for (int k = j-1 ; k >= i-1 ; k--) 
                dp[j] = max (dp[j] , (a[j]&dp[k])) ;
        }
    }


    // for (int i = 1 ; i <= n ; i++)
    //     cout << dp[i] << "\n" ;

    for (int i = m ; i <= n ; i++)
       dp[0] = max(dp[i],dp[0]) ;

    cout << dp[0] ;

    return 0 ;
}