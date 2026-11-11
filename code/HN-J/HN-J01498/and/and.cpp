#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, ccc, a[N];
void dfs(int step, int cnt, int s) {
	if(cnt + n - step + 1 < m) return ;
	if(step > n || cnt == m) {
		if(cnt < m) return ;
		ccc = max(ccc, s);
		return ;
	}
	if(s != -1) dfs(step + 1, cnt + 1, (s & a[step]));
	else dfs(step + 1, cnt + 1, a[step]);
	dfs(step + 1, cnt, s);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n <= 20) {
		dfs(1, 0, -1);
		cout << ccc;
		return 0;
	}
	if(m == 1) {
		int maxn = 0;
		for(int i = 1; i <= n; i++) maxn = max(maxn, a[i]);
		cout << maxn;
		return 0;
	}
	if(m == 2 && n <= 7000) {
		int maxn = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if((a[i] & a[j]) > maxn) maxn = (a[i] & a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	if(m == n) {
		int ans = a[1];
		for(int i = 2; i <= n; i++) ans &= a[i];
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int ans = 2147483647, cnt = 1;
	for(int i = n; cnt <= m && i >= 0; i--) {
		int x = a[i];
		while(x % 2 == 0) x /= 2;
		if(x == 1) continue;
		cnt++;
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
