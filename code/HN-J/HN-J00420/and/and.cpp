#include <bits/stdc++.h>
using namespace std;
int ans = INT_MIN;
int cnt;
int n, m;
int a[200005];
bool is[200005];
void dfs(int x) {
	if(cnt > m) {
		return;
	}
	if(cnt == m) {
		int s = INT_MAX;
		for(int i = 1; i <= n; i++) {
			if(is[i]) {
				s &= a[i];
			}
		}
		ans = max(ans, s);
		return;
	}
	if(x > n) {
		return;
	}
	cnt++;
	is[x] = true;
	dfs(x + 1);
	cnt--;
	is[x] = false;
	dfs(x + 1);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(m == 1) {
		int maxn = 0;
		for(int i = 1; i <= n; i++) {
			maxn = max(maxn, a[i]);
		}
		cout << maxn;
		return 0;
	}
	if(m == 2) {
		int maxn = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				maxn = max(maxn, a[i] & a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	if(m == n) {
		int ans = INT_MAX;
		for(int i = 1; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}

