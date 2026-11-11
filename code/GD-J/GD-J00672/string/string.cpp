#include <bits/stdc++.h>
#define int long long
#define N 200005
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define inf 1e18
using namespace std;
int n;
struct node {
	int x;
	char c;
} a[N];
#undef int
int main() {
#define int long long
	freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
	cin >> n;
	rep (i, 1, n) cin >> a[i].x >> a[i].c;
	int l = 1, r = n, ans = 0;
	while (l < r) {
		int mn = min(a[l].x, a[r].x);
		if (a[l].c != a[r].c) ans += mn;
		a[l].x -= mn, a[r].x -= mn;
		if (!a[l].x) l++;
		if (!a[r].x) r--;
	}
	cout << ans;
	return 0;
}
