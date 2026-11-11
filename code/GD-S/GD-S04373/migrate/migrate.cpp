#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[2000006];
int mi[2000006];
map<int, ll> dp[200006];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		if(c >= 0){
			int n;ll d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)cin >> d;
			cout << 0 << endl;
			continue;
		}
		int n;ll d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)cin >> a[i];
		int p = n;
		for(int i = n; i > 0; i--){
			while (a[i] - a[p - 1] <= d || p > 1)p--;
			mi[i] = p;
		}

		for(int i = 1; i <= n; i++)dp[i].clear();
		dp[1][0] = 1;

		for(int i = 2; i <= n; i++){
			dp[i][0] = 1;
			for(int j = mi[i]; j <= i; j++){
				dp[i][i - j] += dp[j][j - mi[i]];
				if(j != mi[i]) dp[i][i-j] += dp[i][i - j + 1];

			}
		}
		ll cnt = 0;
		for(int i = 2; i <= n; i++){
			for(int j = mi[i]; j <= i; j++){
				if(dp[i][i - j] / dp[j][0] == 2)cnt++;
	}}
	cout << cnt;
	}
	return 0;
}
//监考员不会传文件，导致我只能shang4shan4ruo4shui3 10mins 
//别给我判晚离开考场作弊了 
