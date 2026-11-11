#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
//#define DEBUG(x, y) (cerr << :(x) << ":" << x << ' ' << (y))

constexpr int MAXN = 5e5+10;
int n, m;
LL a[MAXN];
LL now;
int ans, p;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal4.in", "r", stdin);
//	freopen("myout.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i<=n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	now = 0, p = 1;
	for (int i = 1; i<=n; i++) {
		while (p < i && now > m) now -= a[i]-a[p++];
		ans = max(ans, i-p+1);
		if (i < n) {
			now += (LL) (i-p+1) * (a[i+1]-a[i]);
		}
	}
	cout << ans;
	return 0;
}

