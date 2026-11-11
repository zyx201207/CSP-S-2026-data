#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int l, r;
long long cnt;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> c[i];
	l = 1;
	r = n;
	while (l < r) {
		if (a[l] == a[r]) {
			if (c[l] != c[r])
				cnt += a[l];
			l ++;
			r --;
		}
		if (a[l] < a[r]) {
			if (c[l] != c[r])
				cnt += a[l];
			a[r] -= a[l];
			l ++;
		}
		if (a[l] > a[r]) {
			if (c[l] != c[r])
				cnt += a[r];
			a[l] -= a[r];
			r --;
		}
	}
	cout << cnt << endl;
	return 0;
}