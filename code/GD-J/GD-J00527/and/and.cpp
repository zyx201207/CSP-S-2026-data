#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
int ok[32];
bool dp[N][32], low[N];
int ans, had;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 30; j++) {
			if((a[i] >> j) & 1) dp[i][j] = 1, ok[j]++;
		}
	}
	for(int j = 30; j >= 0; j--) {
		if(ok[j] < m) continue;
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(dp[i][j] && !low[i]) cnt++;
		}
		if(cnt >= m) {
			ans += (1 << j);
			for(int i = 1; i <= n; i++) {
				if(!dp[i][j]) low[i] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}
