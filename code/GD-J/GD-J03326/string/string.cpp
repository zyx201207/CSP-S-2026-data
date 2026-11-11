#include <bits/stdc++.h>
using namespace std;
long long dp[2005][2005];
long long cal(string S) {
	memset(dp , 0x3f , sizeof(dp)); // 初始化为大数
	long long n = (long long)S.size(); 
	for(long long i = 0; i < n; i++) dp[i][i] = 0; //自身为0 
	for(long long i = 0; i < n; i++) dp[i + 1][i] = 0; //注意：len=2时，会调用dp[i+1][i]，因为两头一样，所以中间是空的，是0 
	for(long long len = 2; len <= n; len++) { //长度 
		for(long long i = 0; i < n; i++) { //起点 
			long long j = (i + len - 1); //终点 
			if(S[i] == S[j]) { //两头相等 
				dp[i][j] = min(dp[i][j] , dp[i + 1][j - 1]);
			} else {
				dp[i][j] = min(dp[i + 1][j] , dp[i][j - 1]) + 1;
			}
		}
	}
	return dp[0][n - 1];
}
int main() {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	long long N;
	cin >> N;
	string tot;
	for(long long i = 1; i <= N; i++) {
		long long c;
		string s;
		cin >> c >> s;
		while(c--) tot += s;
	}
	cout << cal(tot);
	return 0;
} 
