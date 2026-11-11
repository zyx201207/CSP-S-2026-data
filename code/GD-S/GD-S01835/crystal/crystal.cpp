#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n;
	long long m;
	cin >> n >> m;
	int l = 1, r = n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	while (l < r) {
		int mid = l + r >> 1;
		long long cur = 1e18;
		for (int i = 1; i <= n - mid + 1; i++)
			cur = min(cur, a[i + mid - 1] * mid - (s[i + mid - 1] - s[i - 1]));
		if (cur <= m)
			l = mid + 1;
		else
			r = mid;
	}
	cout << r - 1 << '\n';
	return 0;
}
