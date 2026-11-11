// gu fen : 25 ~ 55  
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], n ,m, rq, ans;
void dfs(int now, int cnt, int sum){
	if(now > n && cnt == m){
		ans = max(ans, sum);
		return;
	}
	if(n - now + 1 < m - cnt) return;
	if(cnt > m) return;
	dfs(now + 1, cnt, sum);
	if(sum != -1) dfs(now + 1, cnt + 1, sum & a[now]);
	else dfs(now + 1, cnt + 1, a[now]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 1) rq = a[i];
		else rq &= a[i];
	}
	if(m == n){
		cout << rq;
		return 0;
	}
	if(m == 1){
		cout << *max_element(a + 1, a + n + 1);
		return 0;
	}
	if(m == 2){
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++) ans = max(ans, a[j] & a[i]);
		cout << ans;
		return 0;
	}
	if(n <= 20){
		dfs(1, 0, -1);
		cout << ans;
		return 0;
	}
	else{
		sort(a + 1, a + n + 1, greater<int>());
		int ans = a[1];
		for(int i = 1; i <= m; i++) ans = ans & a[i];
		cout << ans;
	}
}
// 达成时间：11:29
// difference :yellow/green-
