#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[5005];
long long dp[5005][5005];
bool cmp(long long a, long long b){
	return a < b;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++){
		dp[1][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= n; j++){
			dp[j][i] = 1e9;
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= i; j++){
			for(int k = j - 1; k < i; k++){
				dp[j][i] = min(dp[j][i], dp[j - 1][k] + (a[i] - a[k]) * (j - 1));
			}
		}
	}
//	printf("%d", 1);
	for(int i = n; i > 0; i--){
		for(int j = i; j <= n; j++){
			if(dp[i][j] <= m){
				printf("%d", i);
				return 0;
			}
		}
	}
	return 0;
}

