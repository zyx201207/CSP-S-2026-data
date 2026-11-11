//GZ-S00098，刘信果，贵阳市第一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5005;
int c, T, n, d, a[N], ne[N], ans, cnt[N], stp[N], fir[N], dd[N];

int next(int i) {
	int l = i, r = n, res = n;
	while (l <= r) {
		int mid = l+r>>1;
		if (a[mid]-a[i] > d) r = mid-1;
		else res = mid, l = mid+1;
	}
	return res;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			ne[i] = next(i);
		ans = 0;
		for (int l = 1; l <= n; ++l) {
			for (int i = 0; i <= n+1; ++i)
				stp[i] = cnt[i] = fir[i] = dd[i] = 0;
			int lim = n;
			for (int i = l; i < n; ++i)
				if (a[i+1]-a[i] > d) {
					lim = i;
					break;
				}
			for (int i = l; i <= lim; ++i)
				for (int j = ne[i]; j > i && !stp[j]; --j)
					stp[j] = stp[i]+1;
			for (int i = l; i <= lim; ++i)
				if (!fir[stp[i]]) fir[stp[i]] = i;
			fir[stp[lim]+1] = lim+1;
			dd[l] = 1, dd[l+1] = -1;
			int sum = 0;
			for (int i = l; i <= lim; ++i) {
				sum = min(sum+dd[i], 100ll), cnt[i] = sum;
				if (ne[i] >= fir[stp[i]+1]) {
					dd[fir[stp[i]+1]] += cnt[i];
					dd[ne[i]+1] -= cnt[i];
				}
				if (cnt[i] == 2) ans++;
			}
//			cout << "sssssssss"<<l<<endl;
//			for (int i = 1; i <= n; ++i)
//				cout << ne[i] << "  "<<stp[i]<<" "<<cnt[i]<<" "<<fir[i]<<endl;
		}
		cout << ans << endl;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
