#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2 * 1e5 + 10;
long long n, a[MAX_N], num, lal, lar, sum[MAX_N], ans = 0;
char c[MAX_N], ch;
bool flag;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		if (i == 1) {
			ch = c[i];
		}
		if (c[i] != ch) {
			flag = true;
		}
		sum[i] = sum[i - 1] + a[i];
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	if (!flag) {
		cout << "0";
		return 0;
	}
	int cnt = 1;
	num = sum[n] / 2;
	for (int i = 0; i < num; i++) {
		if (s[i] != s[n- i + 1]) {
			ans++;
		}
	}
//	long long k = 0;
//	int cnt = 1, r = n;
//	while (k < num) {
//		if (l >=r) {
//			break;
//		}
//		if (c[cnt] != c[r]) {
//			if (a[cnt] > a[r]) {
//				ans += a[r];
//				k = sum[cnt - 1] + a[r];
//				a[cnt] -= a[r];
//				r--;
//			} else if (a[cnt] <= a[r]) {
//				ans += a[cnt];
//				a[r] -= a[cnt];
//				k = sum[cnt - 1] + a[cnt];
//				cnt++;
//			}
//		} else {
//			if (a[cnt] < a[r]) {
//				cnt++;
//			} else {
//				r++;
//			}
//		}
//	}
	cout << ans;
	return 0;
}
