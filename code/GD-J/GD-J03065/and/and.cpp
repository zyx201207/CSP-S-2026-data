#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005], dp[2005][2005], k = 2;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		dp[a[i]][1] = a[i];
	} 
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(k - 1 > 0 && k <= m){
				if((dp[a[i]][k-1] & a[j]) > dp[a[i]][k-1]){
					dp[a[i]][k] = dp[a[i]][k-1] & a[j];
					k++;
				}
				else dp[a[i]][k] = dp[a[i]][k-1];
			}
		}
	}
//	d(1, a[1], 1);
	cout << dp[n][m];
	return 0;
}
