#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
int n, m;
int a[MAXN];
long long dp[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "a", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = -1;
	}
	dp[0] = 2e30 - 1;
	dp[1] = a[1];
	for(int i = 2; i <= n; i++){ 	
		for(int j = m; j >= 0; j--){ 
			if(dp[j - 1] == -1) continue;
			dp[j] = max(dp[j], a[i] & dp[j - 1]);
		}
	}
	cout << dp[m];
	return 0;
}
