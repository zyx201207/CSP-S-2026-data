#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 2e5+5;
constexpr int M = 2e5+5;
int a[N];
bool invalid[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int mxn = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i],mxn = max(mxn,a[i]);
	int pos = -1;
	while (mxn) mxn >>= 1,++pos;
	int ans = 0;
	for (int j = pos; j >= 0; --j) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (invalid[i]) continue;
			bool x = ((a[i] >> j) & 1);
			cnt += x;
		}
		if (cnt < m) continue;
		ans += (1 << j);
		int ansinner = (1LL << 31) - 1;
		for (int i = 1; i <= n; ++i) {
			if (invalid[i]) continue;
			bool x = ((a[i] >> j) & 1);
			if (x == 0) invalid[i] = true;
			else if (cnt == m) ansinner &= a[i];
		}
		if (cnt == m) return cout << ansinner << endl,0;
	}
	cout << ans << endl;
	return 0;
}
