#include<iostream>
using namespace std;
int main(){
	int c = 0; int n = 0; int m = 0; int d = 0; int q = 0; 
	int k = 0; int a = 0; int t = 0; 
	
	cin >> c >> n >> m >> d >> q;
	int w[m];
	int _t[n + 1][m + 1];
	for(int i = 0;i <= n + 1;i ++){
		for(int j = 0;j <= m + 1;j ++){
			_t[i][j] = 0;
		}
	}
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		cin >> k;
		for(int j = 1;j <= k;j ++){
			cin >> a >> t;
			_t[i][a] = t;
		}
	}
	int r = 0; cin >> r;
	int x[r]; int y[r];
	
	int dp[n + 1][m + 1];
	for(int i = 0;i <= n + 1;i ++){
		for(int j = 0;j <= m + 1;j ++){
			dp[i][j] = 0;
		}
	}
	for(int i = 0;i < r;i ++){
		cin >> x[i] >> y[i];
		for(int j = 1;j <= n + 1;j ++){
			for(int l = 1;l <= m + 1;l ++){
				dp[i][j] = min(dp[i - 1][j -1] + dp[i - 1][j],dp[i - 1][j -1] + dp[i][j - 1]);
			}
		}
	}
	
	for(int i = 0;i < r;i ++){
		cout << dp[x[i]][y[i]] << endl;
	}
	
	return 0;
}
