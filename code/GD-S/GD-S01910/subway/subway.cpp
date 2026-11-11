#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m , c , d , q;
const int maxm = 3e4 + 10 , maxn = 600 , maxp = 1200;
int w[maxm];
int a[maxn][maxm] , t[maxn][maxm];
int dp[maxp][maxp];
signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++){
		cin >> w[i];
	}
	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= m ; j++){
			dp[i][j] = 1e18;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		int ki;
		cin >> ki;
		for(int j = 1 ; j <= ki ; j++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 1 ; j <= ki ; j++){
			for(int k = 1 ; k <= ki ; k++){
				if(j == k) continue;
				dp[a[i][j]][a[i][k]] = min(dp[a[i][j]][a[i][k]] , t[i][j] + t[i][k]);
				dp[a[i][k]][a[i][j]] = min(dp[a[i][k]][a[i][j]] , t[i][k] + t[i][j]);
			}
		}
	}
	for(int i = 1 ; i <= m ; i++) dp[i][i] = 0;
	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= m ; j++){
			for(int k = 1 ; k <= m ; k++){
				dp[i][j] = min(dp[i][k] + dp[k][j] , dp[i][j]);
			}
		}
	}
	while(q--){
		int s1 , e1;
		cin >> s1 >> e1;
		cout << w[e1] + w[s1] + dp[s1][e1] << '\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
