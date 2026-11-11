#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long p[1000005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long n, m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(long long i = 1; i <= n; i++) {
		p[i] = a[i + 1] - a[i];
	}
	long long ans = -1;
	long long l = 1, r = 1, sum = 0;
	while(r != n) {
		if(sum <= m) {
			ans = max(ans, r - l + 1), r++;
			sum = sum + p[r - 1] * (r - l);
		} else {
			l++, sum = sum - a[r] + a[l - 1];
		}
	}
	cout << ans;
	return 0;
}
