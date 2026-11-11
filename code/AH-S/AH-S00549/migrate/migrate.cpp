#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t, a[N];
int read() {
	int s = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { s = s * 10 + ch - '0'; ch = getchar(); }
	return s * f;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	c = read(), t = read();
	while (t--) {
		int n = read(), d = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		for (int i = 2; i <= n; i++)
			a[i] += a[i-1];
		cout << a[n] << endl;
	}
	return 0;
}
