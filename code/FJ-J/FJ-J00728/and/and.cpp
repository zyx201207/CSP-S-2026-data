#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001], dp[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m;
	dp[0] = 0b111111111111111111111111111111;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = m; j >= 1; j--){
			dp[j] = max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout << dp[m];
	return 0;
}
