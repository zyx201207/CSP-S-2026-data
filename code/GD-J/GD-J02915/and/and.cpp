#include<bits/stdc++.h>
using namespace std; 
long long n, m, a[1010101], ans, mx;
void dfs(long long pos, long long sum, long long cnt) {
	if (cnt == m) {
		ans = max(ans, sum);
		return;
	}
	if (pos > n) return;
	if (sum == 0) dfs(pos + 1, a[pos], cnt + 1);
	else dfs(pos + 1, (sum & a[pos]), cnt + 1);
	dfs(pos + 1, sum, cnt);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if (n <= 20) {
		dfs(1, 0, 0);
		cout << ans;
		return 0;
	}
	else if (m == 1) {
		cout << mx;
		return 0;
	}
	else if (m == n) {
		long long cc = a[1];
		for (long long i = 2; i <= n; i++) cc = (cc & a[i]);
		cout << cc;
		return 0;
	}
	else if (m == 2) {
		ans = 0;
		for (long long i = 1; i <= n; i++) {
			for (long long j = i + 1; j <= n; j++) {
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
	}
	else {
		sort (a + 1, a + 1 + n, greater<long long>());
		long long k = a[1];
		for (long long i = 2; i <= m; i++) {
			k ^= a[i];
		}
		cout << k;
	}
} 
/*
7
4
1 3 3 2 1 2 3
*/
