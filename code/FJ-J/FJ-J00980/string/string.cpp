#include <bits/stdc++.h>
using namespace std;

struct node {
	long long a;
	char c;
} d[200005];

long long n, l = 1, r, ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) cin >> d[i].a >> d[i].c;
	r = n;
	while (l <= r) {
		long long k = min(d[l].a, d[r].a);
		if (d[l].c != d[r].c) ans += k;
		d[l].a -= k;
		d[r].a -= k;
		if (!d[l].a) l++;
		if (l == r) break;
		if (!d[r].a) r--;
	}
	cout << ans;
	return 0;
}