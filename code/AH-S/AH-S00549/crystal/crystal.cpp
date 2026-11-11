#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], b[N], ans;
int read() {
	int s = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { s = s * 10 + ch - '0'; ch = getchar(); }
	return s * f;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read(); b[i] = a[i];
	}
	int pd = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) pd = 2;
	}
	if (pd == 1) {
		for (int i = 1; i <= n; i++)
			if ((1 + i) * i / 2 <= m) ans++;
		cout << ans + 1 << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 2; i <= n; i++)
		b[i] += b[i-1];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) / 2;
			int cnt = i - mid + 1;
			int k = cnt * a[i] - b[i] + b[mid-1];
			if (k <= m) r = mid;
			else l = mid + 1;
		}
		int tmp = i - r + 1;
		ans = max(tmp, ans);
	}
	cout << ans << endl;
	return 0;
}
