#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while(t){
		t --;
		long long n, d;
		cin >> n >> d;
		int dis[200000];
		for(long long i = 0; i < n; i ++){
			cin >> dis[i];
		}
		long long dp[200000];
		long long ans = 0;
		long long cnt = 0;
		for(long long t = 0; t < n - 3; t ++){
		cnt = 0;
		for(long long i = t ;i < n; i ++){
			cnt = 0;
			dp[i] = i;
			for(long long j = t; j < i; j ++){
				if(dis[i] - dis[j] <= d){
					dp[i] = min(dp[i], dp[j] + 1);
					if(dp[j] + 1 <= dp[i]){
//						cout << dp[i] << " " << (dp[j] + 1) << endl;
						cnt ++;
						dp[i] = dp[j] + 1;
					}
				}
			}
//			cout <<"next" << endl;
			if(cnt == 2){
				ans ++;
			}
		}
//		cout << "----- " << ans << " -----" << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
