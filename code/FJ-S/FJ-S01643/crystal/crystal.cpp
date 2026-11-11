#include <bits/stdc++.h>
#define el "\n"
#define sp " "
#define r0 return 0
#define fi first
#define se second
#define F(i, a, b, c) for (int i = a; i <= b; i += c)
#define getmid(l, r) l + (r - l) / 2

using namespace std;
typedef long long ll;
typedef string str;

int n;
ll m;
ll a[500005];
ll p[500005];

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	F(i, 1, n, 1) {
		cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	F(i, 1, n, 1) {
		p[i] = p[i - 1] + a[i];
	}
	int ans = 1;
	F(i, 1, n, 1) {
		int l = -1, r = i + 1;
		while (l + 1 < r) {
			int mid = getmid(l, r);
			if ((mid - 1) * a[i] - (p[i - 1] - p[i - mid]) <= m) {
				l = mid;
			} else {
				r = mid;
			}
		}
		ans = std::max(ans, l);
	}
	cout << ans << el;
	r0;
}
/*
5 12
-3 -1 2 2 3
-1 -1 2 2 3
-1 2 2 2 3
-1 2 2 3 3

*/
