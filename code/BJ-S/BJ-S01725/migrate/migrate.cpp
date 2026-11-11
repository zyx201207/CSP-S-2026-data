#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int a[2000005];
int f1[2000005];
int f2[2000005];
int cnt;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		cnt = 0;
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		for (int s = 1; s <= n; s ++) {
			memset(f1, 0, sizeof f1);
			memset(f2, 0, sizeof f2);
			f2[s] = 1;
			for (int i = s + 1; i <= n; i ++) {
				int mina = 1e18;
				for (int j = i - 1; a[i] - a[j] <= d && j >= s; j --)
					mina = min(mina, f1[j]);
				f1[i] = mina + 1;
				for (int j = i - 1; a[i] - a[j] <= d && j >= s; j --)
					if (f1[j] == f1[i] - 1)
						f2[i] += f2[j];
				if (f2[i] == 2)
					cnt ++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}