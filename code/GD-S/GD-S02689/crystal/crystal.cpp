#include <bits/stdc++.h>
using namespace std;
int n, len;
long long m, a[500001], l = LLONG_MAX, r = LLONG_MIN, mid, cha[500001], cnt, ans = -1, pref[500002], addd;
bool chk(long long p) {
	len = 0;
	for (int i = n; i >= 1; --i) {
		if (a[i] <= p) cha[++len] = p - a[i];
	}
	long long m1 = m;
	cnt = 0;
	for (int i = 1; i <= len; ++i) {
		m1 -= cha[i];
		if (m1 < 0) {
			break;
		}
		++cnt;
	}
	printf("%lld %lld %lld %d\n\n", cnt, p, ans, cnt > ans);
	return cnt > ans;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	ios :: sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
//	pref[0] = -a[1];
	pref[1] = a[1];
	for (int i = 1; i <= n; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}
////add(1, a[1]);
//	for (int i=1;i<=n;++i){
//		add(i + 1,a[i]);
//	}
	for (long long i = 1; i <= n; ++i) {
		l = 1;
		r = i;
		while (l <= r) {
			mid = (l + r) >> 1;
//			printf("%lld-th from %lld tot %lld(%lld %lld)\n", i, mid,(que(i) - que(mid)) - (i - mid) * a[i], que(i), que(mid));
			if (-(pref[i] - pref[mid]) + (i - mid) * a[i] > m) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		ans = max(ans, (i - r));
	}
	cout << ans;
//	l = a[1];
//	r = a[n];
//	printf("%lld %lld\n", l, r);
//	while (l <= r) {
//		mid = (l + r) >> 1;
//		if (!chk(mid)) {
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//			printf("%lld (%lld) is the new king val: \n", mid, 1, cnt);
//			ans = cnt;
//		}
////		if (cnt > ans) {
//			
////			for (int i = 1; i <= len; ++i) {
////				cout << cha[i] << " ";
////			}
////			cout << '\n';
////			long long tmp = 0, dd = 0;
////			for (int i = 1; i <= n; ++i) {
////				tmp += abs(a[i] - a[mid]);
////				++dd;
////				if (tmp > m || a[i] == 0 && dd > 30) {
////					break;
////				}
////				cout << dd << "-th " << a[i] << ":" << tmp << "    ";
////			}
////			cout << endl;
////		}
//	}
//	chk(71);
//	if (cnt > ans) {
//			printf("%lld (%lld) is the new king val: %d\n", 71, 71, cnt);
//			ans = cnt;}
//	cout << ans;
//	for (int i = 1; i <= n; ++i) {
//		int l = i - 1, r = i + 1;
//		long long m1 = m, tmp = 0;
//		while (m1 >= 0) {
//			long long cur = LLONG_MAX;
//			if (l >= 0 && a[l] <= a[i]) {
//				cur = min(cur, a[i] - a[l]);
//				--l;
//			}
//			if (r <= n && a[r] <= a[i]) {
//				cur = min(cur, a[i] - a[r]);
//				++r;
//			}
//			m1 -= cur;
//			if (m1 < 0) {
//				break;
//			}
//			++tmp;
//		}
//		if (tmp > ans) {
//			cout << i << " is the new king: ";
//			ans = tmp;
//		}
//	}
//	cout << ans + 1;
}
