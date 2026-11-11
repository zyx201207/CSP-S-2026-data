#include <bits/stdc++.h>
using namespace std;
long long n, a[100005],m, x,dp[15025][15025];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(m == 1){
		long long maxn = 0;
		maxn = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> x;
			maxn = max(maxn,x);
		}
		cout << maxn;
		return 0;
	}
	if(n <= 15025){
		long long maxn = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i];
		}
		for(int i = 1 ; i <= n ; i++){
			dp[i][1] = max(a[i],dp[i-1][1]);
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = 2 ; j <= m; j++){
				dp[i][j] = max((dp[i-1][j-1] & a[i]),dp[i-1][j]);
			}
		}
			
		cout << dp[n][m];
		return 0;
	}
	
	return 0;
}
