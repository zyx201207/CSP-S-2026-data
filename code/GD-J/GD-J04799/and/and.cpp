#include <bits/stdc++.h>
using namespace std;

long long n, m, s[200005], plan[200005], ans = -1e18, vis[200005]; 

void dfs(long long step){
	if(step == m + 1){
		long long temp = plan[1];
		for(int i = 2;i <= m; i++)  temp &= plan[i];
		ans = max(ans, temp);
		return ;
	}
	for(int i = 1;i <= n; i++){
		if(vis[i] == 0){
			plan[step] = s[i];
			vis[i] = 1;
			dfs(step + 1);
			plan[step] = 0;
			vis[i] = 0;
		}
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n; i++)  cin >> s[i];
	if(m == n){
		long long temp = s[1];
		for(int i = 2;i <= n; i++)  temp &= s[i];
		cout << temp;
		return 0;
	}
	if(m == 1){
		long long ans = -1e9;
		for(int i = 1;i <= n; i++)  ans = max(ans, s[i]);
		cout << ans;
		return 0;
	}
	if(m == 2){
		long long ans = -1e9;
		for(int i = 1;i <= n - 1; i++){
			for(int j = i + 1;j <= n; j++){
				long long temp = (s[i] & s[j]);
				ans = max(ans, temp);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n - 1){
		long long temp = s[1], ans = -1e9;
		for(int i = 2;i <= n; i++)  temp &= s[i];
		for(int i = 1;i <= n; i++){
			long long now = (temp & s[i]);
			ans = max(ans, now);
		}
		cout << ans;
		return 0;
	}
	
	dfs(1);
	cout << ans;
	
	return 0;
}
