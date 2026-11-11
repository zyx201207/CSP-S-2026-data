#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 2e18;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		ll n, d, ans = 0;
		cin >> n >> d;
		vector<ll> a(n + 1);
		vector<vector<ll>> dt(n + 1, vector<ll>(n + 1, INF));
		vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
		for(int i=1; i<=n; i++){
			cin >> a[i];
			dt[i][i] = 0;
			dp[i][i] = 1;
			for(int j=1; j<i; j++){
				int k = i - 1;
				while(k >= j && a[i] - a[k] <= d){
					dt[j][i] = min(dt[j][i], dt[j][k] + 1);
					k--;
				}
				k = i - 1;
				while(k >= j && a[i] - a[k] <= d){
					if(dt[j][k] + 1 == dt[j][i]){
						dp[j][i] += dp[j][k];
					}
					k--;
				}
				if(dp[j][i] == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
