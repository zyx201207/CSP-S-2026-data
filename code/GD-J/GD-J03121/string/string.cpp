#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
char c[MAXN], s[MAXN];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	bool flag1 = true;
	int len = 1, sum =0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		sum += a[i];
		for (int j = 1; j <= a[i]; ++j) {
			s[len++] = c[i];
		}w
	}
	bool flag2 = true;
	for (int i = 1; i <= len; ++i) {
		if (s[i] != s[len + 1 - i]) {
			flag2 = false;
		}
	}
	long long ans = 0;
	for (int i = 0, j = sum - 1; i <= (len - 1) / 2, j >= (len - 1) / 2; ++i, --j) {
//		cout << a[i] << ' ' << a[j] << '\n';
		if (s[i] != s[j]) {
			ans++;
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i) {
		if (i >= 2) {
			if (c[i] != c[i - 1]) {
				flag1 = false;
				break;
			}
			else {
				flag1 = true;
			}
		}
	}
	//	for (int i = 1; i <= MAXN; ++i) {
	//		for (int j = 1; j <= 1e9; ++j) {
	//			cout << 1 << '\n';
	//		}
	//	}
	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	if (flag2 == true) {
		cout << 0 << '\n';
		return 0;
	}
	if (flag1 == true) {
		cout << 0 << '\n';
		return 0;
	}
	return 0;
}
//s_i=s_(l+1-i)

