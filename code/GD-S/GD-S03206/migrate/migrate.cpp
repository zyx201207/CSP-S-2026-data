#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,d;
	cin >> n >> d;
	
	vector<int>s(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	
	vector<vector<int>>p(n + 1,vector<int>(n + 1));
	vector<vector<int>>dp(n + 1,vector<int>(n + 1,1e18));
	for(int i = 1;i < n;i++){
		if(s[i + 1] - s[i] <= d){
			dp[i][i + 1] = 1;
			p[i][i + 1] = 1;
		}
	}
	for(int len = 3;len <= n;len++){
		for(int l = 1;(l + len - 1) <= n;l++){
			int r = (l + len - 1);
			if(s[r] - s[l] <= d){
				dp[l][r] = 1;
				p[l][r] = 1;
			}else{
				for(int k = l + 1;k < r - 1;k++){
					dp[l][r] = min(dp[l][r],dp[l][k] + dp[k][r]);
				}
			}
		}
	}
	
	vector<vector<bool>>vis(n + 1,vector<bool>(n + 1));
	for(int f = n;f >= 1;f--){
		for(int t = n;t > f;t--){
			if(t - f <= 2){
				break;
			}else{
				if(dp[f][t] == 1){
					for(int nt = t + 1;nt <= n;nt++){
						if(vis[t][nt] == true){
							p[f][nt] = 2;
							vis[f][nt] = true;
						}
					}
				}else{
					int tot = 0;
					for(int k = f + 1;k <= t - 1;k++){
						if(dp[f][k] + dp[k][t] == dp[f][t] and p[f][k] * p[k][t] == 1){
							tot++;
						}
					}
					p[f][t] = tot;
					if(tot == 2){
						vis[f][t] = true;
					}
				}
			}
		}
	}
	
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			ans += vis[i][j];
			
		}
	}
	cout << ans << "\n";
	
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	int T = 1;
	cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
}
