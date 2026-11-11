#include <bits/stdc++.h>
#define int long long
#define r(x) for (int i = 1; i <= x; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 5e5 + 50;
int n, m, a[N], s[N], mx;

int check(int x, int k) {
	return a[k] * (k - x + 1) - (s[k] - s[x - 1]);
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m; r(n) cin >> a[i];
	sort(a + 1, a + n + 1);
	r(n) s[i] = s[i - 1] + a[i];
	r(n) {
		int l = 1, r = i, ans = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i) <= m) 
				r = (ans = mid) - 1;
			else l = mid + 1; 
		}
		mx = max(mx, i - ans + 1);
	}
	cout << mx << "\n";
	return 0;
}
