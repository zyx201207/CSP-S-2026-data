#include<bits/stdc++.h>
using namespace std;
const long long N = 2 * 100000 + 5;
long long n, m, cnt = 0;
long long a[N], dp[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) {
	    cin >> a[i];
	}
	for(long long i = 1; i <= n; i++){
		dp[1] = a[i];
		for(long long j = 2; j <= n; j++){
		    long long x = dp[j];
		    dp[j] = max((dp[j-1] & a[j]), dp[j-1]);
		    if(dp[j] != x) {
		    	cnt++;
			}
		    if(cnt == m) break;
	    }
	}
	cout << dp[m];
	return 0;
}
