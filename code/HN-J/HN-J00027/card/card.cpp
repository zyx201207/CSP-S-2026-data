#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;

int n, m;
int a[N], dp[N], pre[N], lst[M], nxt[N], ans[M];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		lst[a[i]] = i;
	}
	nxt[n + 1] = n + 1;
	for(int i = n; i >= 1; i--){
		if(lst[a[i]] != i) nxt[i] = i;
		else nxt[i] = nxt[i + 1];
	}
	fill(dp + 1, dp + 1 + n, 1);
	for(int i = 1; i <= n; i++){
		dp[nxt[lst[a[i]]]] += dp[i];
		pre[lst[a[i]]] += dp[i], pre[nxt[lst[a[i]]]] -= dp[i];
	}
	for(int i = 1; i <= n; i++){
		pre[i] += pre[i - 1];
		ans[a[i]] += pre[i];
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
/*

*/
