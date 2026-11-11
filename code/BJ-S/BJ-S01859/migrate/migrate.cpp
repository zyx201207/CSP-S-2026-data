#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int c,t,n,dp[N][N],cnt;
long long d,a[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t --){
		memset(a,0x3f,sizeof a);
		memset(dp,0x3f,sizeof dp);
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
			dp[i][i] = 0;
		}
		for(int len = 2;len <= n;len ++){
			for(int l = 1;l + len - 1 <= n;l ++){
				int r = l + len - 1;
				if(a[r] - a[l] <= d){
					dp[l][r] = 1;
				}
				else{
					cnt = 0;
					for(int k = l + 1;k < r;k ++){
						if(dp[l][k] + dp[k][r] < dp[l][r]){
							dp[l][r] = dp[l][k] + dp[k][r];
							cnt = 1;
						}
						else if(dp[l][k] + dp[k][r] == dp[l][r]){
							cnt ++;
						}
					}
					if(cnt == 2)ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
