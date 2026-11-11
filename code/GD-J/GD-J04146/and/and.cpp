#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int dp[MAXN];
int a[MAXN], n, m, ans, ansx;
void dfs(int idx, int sum, int s){
	if(s == m + 1 && idx == n + 1){
		if(s == m + 1) ans = max(ans, sum);
		return;
	}
	dfs(idx + 1, sum & a[idx], s + 1);
	dfs(idx + 1, sum, s);
} 
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		dp[i] = a[i];
	}
	if(m==n){
		ans = a[1];
		for(int i = 2;i <= n;i++){
			ans &= a[i];
		}
	}
	else if(m==1){
		for(int i = 1;i <= n;i++){
			ans = max(ans, dp[i]);
		}
		cout << ans;
		return 0;
	}
	else if(m==2){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
	}
	else if(m==n-1){
		for(int j = 1;j <= n;j++){
			if(j != 1) ansx = a[1];
			else ansx = a[2];
			for(int i = 2;i <= n;i++){
				if(i != j) ansx &= a[i];
			}
			ans = max(ans, ansx);
		}
	}
	else{
		dfs(2, a[1], 1);
	} 
	cout << ans;
	return 0;
}
