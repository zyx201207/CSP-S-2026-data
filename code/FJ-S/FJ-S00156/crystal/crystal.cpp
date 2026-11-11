#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
long long n = 0, m = 0;
long long a[N];

bool check(long long x) {
	long long res = 0;
	long long ans = 0;
	for (int i = 1; i <= x; i++) {
		res += (a[x] - a[i]);
	}
	ans = res;
	for (int i = 2; i + x - 1 <= n; i++) {
		int j = i + x - 1;
//		res = 0;
//		for (int k = i; k <= j; k++) {
//			res += (s[j] - s[k]);
//		}
		res += x * (a[j] - a[j - 1]);
		res -= (a[j] - a[i - 1]);
		ans = min(ans, res);
	}
	return (ans <= m);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}
//	cout << "\n";
//	for (int i = 1; i <= n; i++) {
//		cout << s[i] << " ";
//	}
//	cout << "\n";
	long long l = 1, r = n, res = 0;
	while (l < r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	if (check(r)) {
		res = r;
	}
	cout << res;
//	cout << "\n";
//	cout << check(315275);
	return 0;
}
