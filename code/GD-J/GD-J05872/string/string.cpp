#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 200005;

char a[kMaxN];
long long cnt[kMaxN];
long long cntt = 0;
bool ll[30];
int n;
int look[30];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if (n <= 1) {
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		long long x;
		char y;
		if (!ll[y - 'a']) cntt ++;
		ll[y - 'a'] = true;
		cin >> x >> y;
		a[i] = y;
		cnt[i] = x;
	}
	int mid = n / 2;
	int l = mid, r = (n % 2 == 0) ? mid + 1 : mid + 2;
	while (l != 0) {
		if (a[l] != a[r]) {
			if (cnt[l] < cnt[r]) look[l] ++;
			else look[r] ++;
		}
		l --;
		r ++;
	}
	if (cntt == 1) {
		cout << 0;
		return 0;
	}
	long long ans = 0;
	for (int i = 0; i <= n; i ++) {
		ans += look[i] * cnt[i];
	}
	cout << ans;
//	if (cnt == 1) cout << 0;
	return 0;
}
