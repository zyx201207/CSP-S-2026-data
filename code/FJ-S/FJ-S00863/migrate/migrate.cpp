#include <iostream>
#include <cstring>
#define ll long long
#define gc getchar() 
using namespace std;
const int N = 2e6+10;
inline ll read(){
	ll res = 0,s = 1;
	char x = gc;
	if (x == '-'){
		s = -1;
		x = gc;
	}
	while (x >= '0' && x <= '9'){
		res = res * 10 + (x - '0');
		x = gc;
	}
	return res * s;
}
void solve(){
	ll x[N] = {},n,d,dp[5005][5005] = {},cnt[5005][5005]={};
	memset(dp,63,sizeof(dp));
	n = read(); d = read();
	for (int i = 1;i <= n;i++) x[i] = read();
	for (int i = 1;i <= n;i++) dp[i][i] = 0;
	for (int i = 2;i <= n;i++){
		for (int l = 1,r = l+i-1;r <= n;l++,r++){
			if (i == 2){
				if (x[r] - x[l] <= d){
					dp[l][r] = 1;
					cnt[l][r] = 1;
				}
			}
			else{
				if (x[r] - x[l] <= d){
					dp[l][r] = 1;
					cnt[l][r] = 1;
					continue;
				}
				for (int k = l+1;k <= r-1;k++){
					if (dp[l][k] + dp[k][r] < dp[l][r]){
						dp[l][r] = dp[l][k] + dp[k][r];
						cnt[l][r] = 1;
					}
					else if (dp[l][k] + dp[k][r] == dp[l][r]){
						cnt[l][r]++;
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 1;i <= n;i++){
		for (int j = i+1;j <= n;j++){
			if (cnt[i][j] == 2) ans++;
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	c = read();
	t = read();
	while (t--){
		solve();
	}
	return 0;
}
