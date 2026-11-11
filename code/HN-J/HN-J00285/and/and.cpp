#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005];
long long dp[2005][205];

bool cmp(long long x, long long y){
	return x > y;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);  
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}

	//sort(a + 1, a + n + 1, cmp);
	
	for (int i = 1; i <= n; i ++){
		dp[i][1] = max(dp[i][1], a[i]);
		for (int j = 2; j <= min(i, m); j ++){
			for (int k = i - 1; k >= 1; k --){
				dp[i][j] = max(dp[i][j], dp[k][j - 1] & a[i]);
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++) ans = max(ans, dp[i][m]);
	cout << ans;
	return 0;
}

