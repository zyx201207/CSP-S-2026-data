#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c, t;
	cin >> c >> t;
	while(t--){
		ll n, d;
		cin >> n >> d;
		vector<ll> x(n);
		for(int i = 0; i < n; i++){
			cin >> x[i];
		}
		
		ll ans = 0;
		for(int i = 0; i < n; i++){
			vector<ll> dp(n, 1e9);
			dp[i] = 0;
			for(int j = i + 1; j < n; j++){
				for(int k = i; k < j; k++){
					if(abs(x[j] - x[k]) <= d){
						dp[j] = min(dp[j], dp[k] + 1);
						
					}
				}
				
			}
			
			/*for(int j = i; j < n; j++){
				cout << dp[j] << " ";
			}
			cout << endl;*/
			for(int j = i + 1; j < n; j++){
				ll minx = 1e9;
				for(int k = i; k < j; k++){
					if(abs(x[j] - x[k]) <= d && dp[j] - dp[k] < minx && dp[j] != dp[k]){
						minx = dp[j] - dp[k];
					}
				}
				//cout << minx << endl;
				ll cnt = 0;
				for(int k = i; k < j; k++){
					if(dp[j] - dp[k] == minx && abs(x[j] - x[k]) <= d){
						cnt++;
						//cout << x[j] << " " << x[k] << endl;
					}
				}
				if(cnt == 2){
					ans++;
				}
				//cout << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
