#include <bits/stdc++.h>
using namespace std;
int x[2000010], dp[2000010];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		for(int i=1; i<=n; i++){
			cin >> x[i];
		}
		for(int i=1; i<d; i++){
			dp[i] = 1;
		}
		int ans = 0;
		for(int i=n; i>d; i--){
			dp[i] = dp[i-d] + dp[i-d-1];
			if(dp[i] == 2){
				ans += n - i + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
