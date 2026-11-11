#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
long long a[N], sum;
char c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> a[0] >> c[0];
	for (int i = 1; i < n; ++i) {
		cin >> a[i] >> c[i];
		if (c[i] == c[i - 1])
			a[i - 1] += a[i], n--, i--;
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n / 2; ++i) {
		if (c[i] != c[n - i]) {
			sum += max(a[i], a[n - i]);
		} else if (a[i] != a[n - i]) {
			sum += a[i] - a[n - i];
			a[i + 1] += a[i] - a[n - i];
			a[i] = a[n - i];
		}
	}
	cout << sum;
	return 0;
}