#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 5e2 + 5;
long long n, m;
long long a[N];
long long dp[N][M];
void solve1(){
	cin >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	memset(dp, 0, sizeof(dp)); 
	dp[1][1] = a[1]; 
	for(long long i = 2;i <= n;i++){
		for(long long j = 1;j <= min(i, m);j++){
			if(j == 1) dp[i][j] = max(dp[i - 1][j], a[i]);
			else dp[i][j] = max(dp[i - 1][j - 1] & a[i], dp[i - 1][j]);
		}
	}
	cout << dp[n][m];
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >> n;
	solve1();
	return 0;
}

