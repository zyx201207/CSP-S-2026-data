#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[222222];
int dp[222222];
signed main(){
	int n, m;
	freopen("and.in","r", stdin);
	freopen("and.out","w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp[1] = a[1];
	for(int i = 2; i <= n; i++){
		for(int j = min(i, m); j >= 1; j--){
			if(dp[j - 1] & a[i] != 0)dp[j] = max(dp[j], dp[j - 1] & a[i]);
			else dp[j]  = max(dp[j], a[i]) ;
		//	int tmp = dp[i - 1][j - 1] & a[i];
			///cout << tmp  <<"??"<<i <<"||"<<j<< endl;
		} 
	}
	cout << dp[m];
//	int ans = 1 & 3;
//	cout << ans;
	return 0;
}
