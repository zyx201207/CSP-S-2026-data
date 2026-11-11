#include <bits/stdc++.h>

const int N = 5e5 + 7;

int n;
long long m, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::cin.tie(0), std::cout.tie(0), std::ios::sync_with_stdio(false);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m)
				r = mid;
			else
				l = mid + 1;
		}
//		std::cout << r << ' ' << find_y(r, i) << ' ' <<  ' ' << i << ' ' << m - (a[i] * (i - r + 1) - (s[i] - s[r - 1])) << '\n';
		ans = std::max(ans, i - r + 1);
	}
	std::cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
