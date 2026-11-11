#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, n, a[2000001], dp[200001][200001]; 
	cin >> m >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			dp[i][j] = max(dp[i-1][j], dp[i][j- 1]);
		}
	}
	cout <<dp[m][n];
	return 0;
}
