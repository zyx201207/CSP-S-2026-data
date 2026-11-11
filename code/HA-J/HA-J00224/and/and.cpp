#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200010],ans,dp[2010][2010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		dp[i][1] = a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			for(int k = 2;k <= m;k++){
				dp[i][k] = max(dp[i][k],dp[j][k-1]&a[i]);
//				cout << i << ' ' << k << ' ' << dp[i][k] << '\n';
			}
		}
		ans = max(ans,dp[i][m]);
	}
	cout << ans;
	return 0;
}