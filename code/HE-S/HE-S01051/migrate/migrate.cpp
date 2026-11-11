#include <bits/stdc++.h>

using namespace std;

int c, t;
long long n, d;
long long a[2000005];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		long long maxn = -1, minn = LONG_LONG_MAX;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			maxn = max(maxn, a[i]), minn = min(minn, a[i]);
		}
		int p = (maxn - minn) / (n - 1);
		if (2 * p < d) cout << n * (n - 1) / 2 - n + 1 << endl;
		else cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

