#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int dp[N][2];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		vector<int> a;
		for(int i = 1; i <= n; i++){
			int t;
			cin >> t;
			a.push_back(t);
		}
		dp[0][0] = 0;
		dp[0][1] = 0;
		int ans = 0;
		for(int i = 1; i < n; i++){
			for(int j = min(i, d); j >= 1; j--){
				if(a[i] - a[i-j] > d){
					break;
				}else if(a[i] - a[i-j] < d){
					dp[i][1] = max(dp[i][1], dp[i-j][0]);
					if(dp[i][1] == 0) dp[i][1]++;
				}else{
					dp[i][0] = max(dp[i-d][0], dp[i][0]);
					dp[i][1] = max(dp[i][1], max(dp[i-d][1], dp[i-d][0])+1);
				}
			}
			if(dp[i][0] == 2 || dp[i][1] == 2) ans++;
		}
//		for(int i = 0; i < n; i++){
//			for(int j = 0; j <= 1; j++){
//				cout << dp[i][j];
//			}
//			cout << endl;
//		}
		for(int i = 1; i < n; i++){
			dp[i][0] = 0;
			dp[i][1] = 0;
		}
		cout << ans << '\n';
	}
	return 0;
}
