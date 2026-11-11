#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int n, m;
long long dp[200010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == n){
		int ans = a[1];
		for(int i = 2;i <= n;i++){
			ans = ans & a[i];
		} 
		cout << ans;
		return 0;
	}
	dp[0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = m;j >= 2;j--){
			dp[j] = max(dp[j], dp[j-1]&a[i]);
		}
		dp[1] = max(dp[1], a[i]);
	}
	cout << dp[m] << endl;
	return 0;
}
