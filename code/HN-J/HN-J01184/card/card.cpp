#include<bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;

int n, m, a[N], b[N], ans[N], dp[N], nxt[N];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) b[i] = n + 1;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = n; i >= 1; i--) nxt[i] = b[a[i]], b[a[i]] = i;
	for(int i = 1; i <= n; i++) dp[i] = 1;
	for(int i = 1; i <= n; i++){
		if(nxt[i] <= n) dp[nxt[i]] += dp[i];
		else ans[a[i]] += dp[i], dp[i + 1] += dp[i];
	}
	cout << ans[1];
	for(int i = 2; i <= m; i++) cout << ' ' << ans[i];
	return 0;
}

