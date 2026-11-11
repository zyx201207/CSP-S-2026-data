#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e6 + 10;
int c, t, n, d;
int a[N];
int dis[5002][5002], dp[5002][5002];

void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	if(n <= 500){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dp[i][j] = dis[i][j] = 0;
			}
		}
		for(int i = 1;i <= n;i++) dp[i][i] = 1;
		for(int i = 1;i <= n;i++){
			int pos = i, cnt = 0;
			dis[i][i] = 0;
			while(pos < n){
				cnt++;
				int tn;
				if(a[pos] + d < a[pos + 1]) break;
				else if(a[pos] + d >= a[n]) tn = n;
				else tn = upper_bound(a + 1,a + n + 1, a[pos] + d) - a - 1;
				while(pos < tn){
					pos++; dis[i][pos] = cnt;
				}
			}
		}
		int tot = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				int tn;
				if(a[j] + d < a[j + 1]) continue;
				else if(a[j] + d >= a[n]) tn = n;
				else tn = upper_bound(a + 1,a + n + 1, a[j] + d) - a - 1;
				for(int k = j + 1;k <= tn;k++){
					if(dis[i][k] == dis[i][j] + 1) dp[i][k] += dp[i][j];
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				//cout << dp[i][j] << " ";
				if(i != j && dp[i][j] == 2) tot++;
			}
			//cout << endl;
		}
		cout << tot << endl;
	}
	else{
		int tot = 0;
		int cha = a[2] - a[1];
		int alr = d / cha;
		for(int i = 1;i <= n;i++){
			int fst = min(n, i + alr);
			int scd = min(n, i + alr * 2);
			tot += max(0ll, scd - fst - 1);
		}
		cout << tot << endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
