#include <bits/stdc++.h>
using namespace std ;

int n, m ;

int a[200086] ;

int dp[200005][2005] ;//前i个数中取j个&的最大值 

int main (){
	ios_base::sync_with_stdio(0) ;
	cin.tie();
	cout.tie();
	
	freopen("and.in", "r", stdin) ;
	freopen("and.out", "w", stdout) ;

	cin >> n >> m ; 
	
	for(int i = 1; i <= n; i ++){
		cin >> a[i] ;
	}
	dp[1][1] = a[1] ;
	
	for(int i = 2; i <= n; i++){
		dp[i][i] = dp[i - 1][i - 1] & a[i] ;
		dp[i][1] = max(dp[i - 1][1], a[i]) ;
	}
	for(int i = 2; i <= n; i ++){
		for(int j = 2; j <= min(i, m); j++){
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][j - 1] & a[i])) ;
		}
	}
//	cout << dp[n][m] ;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j++){
			cout << dp[i][j] << ' ';
		}cout << '\n' ;
	}
	return 0 ;
}
