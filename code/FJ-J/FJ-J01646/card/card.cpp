#include<bits/stdc++.h>
using namespace std;
int n , m , a[500010] , ans , nt[500010] , dp[500010];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++){
		memset(nt , 0 , sizeof(nt));
		memset(dp , 0 , sizeof(dp)); ans = 0;
		for (int j = n; j >= 1; j--){
			if (nt[a[j]]){
				dp[j] = dp[nt[a[j]]];
			}else{
				dp[j] = dp[j + 1];
				if (a[j] == i){
					dp[j] = 1;
				}
			}
			nt[a[j]] = j;
			ans += dp[j];
			//cout << ans << " ";
		}
		cout << ans << " "; 
	}
	return 0;
}

