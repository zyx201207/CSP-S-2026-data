#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N];
int fa = 1, fb = 1;
int ef() {
	int l = 1, r = n;
	int fg = 0;
	int cnt = 0;
	int maxn = -1;
	while(l <= r) {
		cnt = 0;
		int mid = (l + r) >> 1;
		int base = a[mid];
		for(int i=1; i<=n; i++) a[i] = base - a[i];
		sort(a + 1, a + n + 1);
		for(int i=1; i<=n; i++) {
			if(a[i] >= 0) m -= a[i], cnt++;
			if(!(m > 0)) {
				fg = 1;
				break;
			}
		}
		if(fg == 0) l = mid + 1;
		else if(fg == 1) r = mid - 1, maxn = max(cnt, maxn);
	}
	return maxn;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(a[i] != i) fa = 0;
	}
	sort(a + 1, a + n + 1);
	int dt = a[2] - a[1];
	for(int i=1; i<=n; i++) if(a[i] - a[i - 1] != dt && i != 1) fb = 0;
	if(fa) {
		int cnt = 0, cm = m;
		for(int i=1; i<=cm, m > 0; i++) {
			m -= i;
			cnt++;
		}
		cout << cnt << '\n';
		return 0;
	} else if(fb) {
		int cnt = 0, cm = m;
		for(int i=1; i<=cm, m > 0; i++) {
			m -= dt * i;
			cnt++;
		}
		cout << cnt << '\n';
		return 0;
	} else {
		int cnt = ef();
		cout << cnt << '\n';
		return 0;
	}
	return 0;
}
