#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	int a[200005] = {};
	int maxn = 0;;
	int maxn_id;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		int t = a[i];
		int cnt = 0;
		while( t != 0){
			cnt += t%2;
			t /= 2;
		}
		if(cnt > maxn){
			maxn = cnt;
			maxn_id = i;
		}
	}
	int dp[200005]={};
	dp[1] = a[maxn_id];
	sort(a+1,a+1+n);
	for (int i = 2; i <= k+1; i++){
		dp[i] = dp[i-1] & a[1];
		int o = 1;
		for (int j = 2; j <= n; j++){
			if(j == maxn_id) continue;
			if(a[j] == 0) continue;
			if(dp[i-1] & a[j] > dp[i]){
				dp[i] = dp[i-1]&a[j];
				o = j;
			}
		}
		a[o] = 0;
	}
	cout << dp[k+1];
	return 0;
}
