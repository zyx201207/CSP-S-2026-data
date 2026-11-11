#include <iostream>
using namespace std;

long long dp[101][101];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	long long k[101];
	for (int i = 1;i <= n;i++) cin >> k[i];
	k[0] = k[1];

	for (int i = 1;i <= n;i++){
		for (int j = m;j >= 1;j--){
			dp[i][j] = max(dp[i-1][j],(dp[i-1][j-1] & k[i]));
		}
	}
	for (int i = 0;i <= n;i++){
		for (int j = 0;j <= m;j++){
			dp[i][j] = k[i];
		}
	}
 
	cout << dp[n][m];
	return 0;
}

