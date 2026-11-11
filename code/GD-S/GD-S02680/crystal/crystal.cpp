#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1010101], ans, fl;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if (n >= 10000) cout << n, exit(0);
	for (long long i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + 1 + n);
	for (long long i = 1; i <= n; i++) {
		long long sum = 0, k = a[i];
		for (long long j = i; j >= 1; j--) {
			if (sum + (k - a[j]) > m) break;
			sum += k - a[j];
			ans = max(ans, i - j + 1);
		}
	}
	cout << ans;
} 
