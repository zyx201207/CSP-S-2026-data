#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using LL = long long;

int n, m;
LL a[N], dp[2001][2001], mx[N], all;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		mx[i] = max(mx[i - 1], a[i]);
	}
	
	for(int i = 1; i <= n; ++i) dp[i][1] = a[i];
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= min(i, m); ++j){
			dp[i][j] = max(max(dp[i][j], dp[i - 1][j]), dp[i - 1][j - 1] & a[i]);
			
		}
	}
	
	cout << dp[n][m];
	return 0;
}
