#include <bits/stdc++.h>

const int N = 500003;
const long long A = 1000000000000;
long long n, m, a[N], b[N];

bool check(long long x) {
	for(int i = x; i <= n; ++i) {
		if(b[i] - b[i-x] - (A-a[i]) * x <= m) {
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a+1, a+1+n);
	for(int i = 1; i <= n; ++i) {
		b[i] = A - a[i];
		b[i] += b[i-1];
	}
	long long l = 1, r = n, mid, ans;
	while(l <= r) {
		mid = (l+r) / 2;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	std::cout << ans;
	return 0;
}
