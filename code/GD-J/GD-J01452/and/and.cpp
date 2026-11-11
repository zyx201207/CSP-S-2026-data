#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int dp[200010];
int a[200020];

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp[1] = a[1];
	for(int i = 2; i <= m; i++){
		dp[i] = max(dp[i - 1], (dp[i - 1] & a[1]));
	}
	for(int i = 2; i <= n; i++){
		for(int j = m; j >= 1; j--){
			dp[j] = max(dp[j], (dp[j - 1] & a[i]));
		}
	}
	cout << dp[m];
	return 0; 
}
 
