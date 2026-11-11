#include<bits/stdc++.h>
using namespace std;
int t , n , c;
long long d , a[2000010];
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		vector<vector<pair<int , int>>> dp(n + 10 , vector<pair<int , int>>(n + 10));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i != j) dp[i][j].second = 10000000;
			}
		}
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j < i; j++){
				if (a[i] - a[j] < d){
					for (int k = 1; k <= j; k++){
						if (dp[k][j].second + 1 == dp[k][i].second){
							dp[k][i].first++;
						}else if (dp[k][j].second + 1 < dp[k][i].second){
							dp[k][i].second = dp[k][j].second + 1;
							dp[k][i].first = 1;
						}
						//cout << 1;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (dp[i][j].first == 2) ans++;
				//cout << dp[i][j].first << " " << dp[i][j].second << "\n";
			}
			//cout << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}
