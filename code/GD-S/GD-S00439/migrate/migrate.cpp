#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;
int n, d[N], cnt[N], L[N], R[N];
ll D, x[N]; 
void dfs(int u) {
	if(u == n) return;
	for(int i = u + 1; i <= R[u]; i++)
		if(d[u] + 1 == d[i]) {
			cnt[i]++;
			dfs(i);
		}
}
void solve() {
	scanf("%d%lld", &n, &D);
	for(int i = 1; i <= n; i++) x[i] = i;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		L[i] = R[i] = i;
		for(int j = i + 1; j <= n; j++)
			if(x[j] - x[i] <= D) R[i] = j;
			else break;
		for(int j = i - 1; j; j--) 
			if(x[i] - x[j] <= D) L[i] = j;
			else break;
 	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) cnt[j] = 0;
		int now = i, C = 0;
		while(now < n && R[now] > now) {
			int nxt = R[now]; C++;
			for(int j = now + 1; j <= nxt; j++) d[j] = C;
			now = nxt; 
		} 
		d[i] = 0;
		dfs(i);
		for(int j = i + 1; j <= n; j++) ans += cnt[j] == 2;
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int Ca, T; scanf("%d%d", &Ca, &T);
	while(T--) solve();
	return 0;
}

