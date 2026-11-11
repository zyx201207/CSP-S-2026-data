#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
long long n, m, a[maxn], del[maxn];
long long sum[maxn];

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) del[i - 1] = (a[i] - a[i - 1]) * (i - 1);
	long long anslen = -1;
	for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + del[i];
	for (long long l = 1, r = 2; l < n; l++) {
		while (r < n && sum[r] - sum[l] <= m) r++;
		if (r == n) {anslen = max (anslen, n - l + 1); break;}
		anslen = max (anslen, r - l + 1);
	}
	cout << anslen << '\n';
	return 0;
} 
