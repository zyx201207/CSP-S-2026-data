#include<bits/stdc++.h>
using namespace std;
long long a[2000020];
int cnt[2000020];
long long dp[2000020];
long long n, d;
void dfs(long long x){
//	cout << x << ": \n";
    for(long long i = x + 1; a[x] + d >= a[i] && i <= n; i++){
  //      cout << i << " ";
        if(dp[i] > dp[x] + 1){
            cnt[i] = 1;
            dp[i] = dp[x] + 1;
        }else if(dp[i] == dp[x] + 1){
            cnt[i]++;
        }
        dfs(i);
    }
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 1; i <= n - d + 1; i++){
			memset(dp, 127, sizeof dp);
			memset(cnt, 0, sizeof cnt);
			dp[i] = 0;
            dfs(i);
            for(int j = 1; j <= n; j++){
                if(cnt[j] == 2){
					ans++;
				}
            }
        }
        cout << ans << "\n";
    }
}
