#include<bits/stdc++.h>
using namespace std;
long long n, sum = 0, ans = 0;
struct Node {
	long long x;
	char y;
};
Node a[200005];
int main ()
{
	freopen(string.in, "r", stdin);
	freopen(string.out, "w", stdout);
	cin >> n;
	for (long long i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	long long l = 1, r = n;
	for (; r - l > 1;) {
		if (a[l].x < a[r].x) {
			if (a[l].y == a[r].y) {
				a[r].x -= a[l].x;
			} else {
				ans += a[l].x;
				a[r].x -= a[l].x;
			}
			l++;
		} else if (a[l].x == a[r].x) {
			if (a[l].y != a[r].y) {
				ans += a[l].x;
			}
			l++, r--;
		} else {
			if (a[l].y == a[r].y) {
				a[l].x -= a[r].x;
			} else {
				ans += a[r].x;
				a[l].x -= a[r].x;
			}
			r--;
		}
	}
	if (l == r) {
		cout << ans;
	} else {
		if (a[l].y == a[r].y) {
			cout << ans;
		} else {
			cout << ans + min(a[l].x, a[r].x);
		}
	}
	return 0;
}
