#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;

int a[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (m == 1) {
		cout << a[n];
		return 0;
	}
	if (m == 2) {
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				ans = max(ans, 1LL * (a[i] & a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	long long ans = a[n];
	for (int i = n; i > n - m; i--) {
		ans = (ans & a[i]);
	}
	cout << ans;
	
	return 0;
	
} 
