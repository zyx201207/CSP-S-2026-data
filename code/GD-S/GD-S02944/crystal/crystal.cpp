#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m ; 

int a[5086] ;
int s[5005][5005];
int dp[5005][5005];//前i个选j个

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	
	cin >> n >> m ;
	
	for (int i = 1; i <= n; i++){
		cin >> a[i] ;
	}
	sort (a + 1, a + n + 1) ;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			s[i][j] = a[i] - a[j] ;
		}
	}
	
	memset (dp, 0x3f, sizeof(dp)) ;
	
	for(int i = 1; i <= n; i++){
		dp[i][0] = 0 ;
		dp[i][1] = 0 ;
		int sum = 0 ;
		for(int j = 1; j <= i; j++){
			sum += s[i][j] ;
		}dp[i][i] = sum ;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + s[i][i - 1] * (j - 1) ) ;
		}
	}
	int maxn = 0 ;
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= i; j ++){
			if(dp[i][j] > m)continue ;
			maxn = j ;
//			cout << dp[i][j] << ' ' ;
		}
//		cout << '\n' ;
	}
	cout << maxn ;
	
//	for(int i = 1; i <= n ;i ++){
//		cout << a[i] << ' ' ;
//	}cout<< '\n' ;
//	
//	for(int i = 1; i <= n; i ++){
//		for(int j = 1; j <= i; j ++){
//			if(dp[i][j] > m)continue ;
//			maxn = j ;
//			cout << s[i][j] << ' ' ;
//		}cout << '\n' ;
//	}
//	
	return 0 ;
}
