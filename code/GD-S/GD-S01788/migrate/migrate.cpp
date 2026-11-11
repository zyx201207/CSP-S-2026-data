#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+9;
int ID, T, n, lstr[N], b[N];
ll d, a[N], dp[N][3];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> ID >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1, j = 1; i <= n; i++){
			while(j < n && a[j+1]-a[i] <= d){
				j++;
			}
			lstr[i] = j;
		}
		ll ans = 0;
		for(int i = 1, j = 1; i <= n; i++){
			while(j < i && a[i]-a[j] > d){
				j++;
			}
			if(i == j){
				b[lstr[i]]++;
				continue;
			}
			if(lstr[j] == i){
				dp[i][2] += dp[j][2];
				dp[i][0] += dp[j][0];
				ans += dp[j][2];
			}else{
				if(lstr[j] == i+1)
					dp[i][1] += dp[j][0]; 
				ans += dp[j][2];
			}
			if(lstr[j+1] == i){
				dp[i][2] += dp[j][1];
				ans += dp[j][1]; 
			}else{
				ans += dp[j][1];
			}
			dp[i][0] += b[i];
			dp[i][1] += b[i+1];
			b[lstr[i]]++;
		}
		for(int i = 1; i <= n; i++){
			dp[i][0] = dp[i][1] = dp[i][2] = 0;
			b[i] = 0;
		}
		cout << ans << endl;
	}
	return 0;
}
