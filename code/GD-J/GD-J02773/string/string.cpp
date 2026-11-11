#include<bits/stdc++.h>
using namespace std;

struct in{
	long long len;
	char c;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vector<in>a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].len >> a[i].c;
	}
	long long l = 1, r = n, ans = 0;
	for (; l <= r; ) {
		long long mn = min(a[l].len, a[r].len);
		a[l].len -= mn;
		a[r].len -= mn;
		if (a[l].c != a[r].c) {
			ans += mn;
		}
		if (a[l].len <= 0) {
			l++;
		}
		if (a[r].len <= 0) {
			r--;
		}
	}
	cout << ans << "\n";
	return 0;
}
