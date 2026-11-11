#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5;
int n, d;
int x[N], dp[N];
int f(int n){
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n == 3) return 2;
	if (dp[n]) return dp[n];
	
	int cnt = 0;
	for (int i = n-1; i>=1; i--){
		if (abs(x[n]-x[i]) <= d) cnt += f(i);
		else break;
	}
	return dp[n] = cnt;
}
void solve(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> n >> d;
	for (int i = 1; i<=n; i++){
		cin >> x[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[1] = 0, dp[2] = 1, dp[3] = 2;
	f(n);
	
	long long ans = 0;
	for (int i = 1; i<=n; i++){
		for (int j = n; j>i; j--){
			if (dp[j]-dp[i] == 2) ans++;
		}
		
	}
	cout << ans << endl;
}
signed main(){
	int c, t;
	cin >> c >> t;
	while (t--){
		solve();
	}
}
