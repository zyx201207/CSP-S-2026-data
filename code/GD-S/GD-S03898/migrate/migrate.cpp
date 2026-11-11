#include<bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX / 3;
int C, T;
long long n, d, x[2000005], ms[2000005], msc[2000005];
int main() {
#ifndef DPSLT_XWX
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#endif
	cin.tie(0) -> sync_with_stdio(0);
	cin >> C >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		long long res = 0;
		for (int i = 1; i <= n; ++i) {
			memset(ms, 0x3f, sizeof ms); memset(msc, 0, sizeof msc);
			ms[i] = 0; msc[i] = 1;
			for (int j = i; j < n; ++j) {
				for (int k = j + 1; x[k] - x[j] <= d && k <= n; ++k)
					if (ms[k] > ms[j] + 1) ms[k] = ms[j] + 1, msc[k] = msc[j];
					else if (ms[k] == ms[j] + 1) msc[k] += msc[j];
			}
			for (int j = i; j <= n; ++j) if (msc[j] == 2) ++res;
		}
		cout << res << '\n';
	}
	return 0;
}
