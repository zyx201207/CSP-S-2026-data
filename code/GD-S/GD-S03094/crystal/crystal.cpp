#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n, m, a[N], Max = 0, cnt;
int cmp (int a, int b) {
	return a > b;
}
void B() {
	if (a[1] - a[2] > m) {
		cout << 0;
		return;
	}
	long long ans = m, j = 1;
	cnt = 1;
	while (ans - a[1] + a[1 + j] >= 0) {
		ans -= a[1] - a[1 + j], cnt++, j++;
		if (1 + j > n) break;
	}
	cout << cnt;
	return;
}
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int ok = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 3) {
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) ok = 0;
		}
	}
	sort (a + 1, a + 1 + n, cmp);
	if (ok) {
		B();
		return 0;
	}
	int i = 1;
	while (i <= n) {
		if (a[i] - a[i + 1] > m) {
			i++;
			continue;
		}
		long long ans = m, j = 1;
		cnt = 1;
		while (ans - a[i] + a[i + j] >= 0) {
		    ans -= a[i] - a[i + j], cnt++, j++;
		    if (i + j > n) break;
		}
		Max = max(Max, cnt);
		i++;
	}
	cout << Max;
	return 0;
 }