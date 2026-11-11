0#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[200005], dp[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp[1] = a[1];
	for(int i = 2; i <= n; i++){
		for(int j = min(i, m); j >= 1; j--){
			if(j == 1)
				dp[1] = max(dp[1], a[i]);
			else if(j == i)
				dp[j] = a[i] & dp[j-1];
			else
				dp[j] = max(dp[j], dp[j-1] & a[i]);
		}
	}
	cout << dp[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
