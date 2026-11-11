#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, a[200005], ans;

void dfs(int step, long long cur, int last) {
	if (step > m) {
		ans = max(ans, cur);
		return ; 
	}
	
	for (int i = last + 1; i <= n; ++i) {
		dfs(step + 1, cur & a[i], i);
	}
}

bool checkB() {
	bool sign = false;
	for (int i = 1; (1 << i) <= n; ++i) {
		if ((1 << i) == n) {
			sign = true;
			break;
		}
	}
	
	if (!sign) return false;
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] != i - 1) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	if (n <= 20) {
		for (int i = 1; i <= n; ++i) {
			dfs(2, a[i], i);
		}
	}
	else {
		if (m == 1) {
			for (int i = 1; i <= n; ++i) ans = max(ans, a[i]);
			cout << ans;
		}
		else if (m == 2) {
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
		else if (m == n) {
			ans = a[1];
			for (int i = 2; i <= n; ++i) ans &= a[i];
		}
		else if (checkB()) {
			long long cur = a[1];
			for (int i = 2; i <= n; ++i) cur &= a[i];
			for (int i = 1; i <= n; ++i) ans = max(ans, cur ^ (!(a[i])));
		}
	}
	
	cout << ans;
	
	return 0;
}
