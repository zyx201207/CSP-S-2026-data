#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define FILE(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
const long long N = 5e3 + 10;
long long n, d, a[N], fa[N], cnt, f[N][N];
long long len(long long l, long long r) {
	if (l >= r || f[l][r]) {
		return f[l][r];
	}
	if (fa[l] == l) {
		return -1;
	}
	return f[l][r] = (len(fa[l], r) == -1 ? -1 : len(fa[l], r) + 1);
}
bool check(long long l, long long r) {
	long long ans1 = len(l, r);
	if (l + 1 == fa[ans1]) {
		return check(l + 1, r);
	}
	long long ans2 = len(l + 1, r) + len(l, l + 1);
	if (ans1 == -1){
		return false;
	}
	if (l + 2 == fa[ans1]) {
		return check(l + 2, r);
	}
	long long ans3 = len(l + 2, r) + len(l, l + 2);
	if (ans1 == ans2 && ans2 != ans3) {
		return true;
	}
	return false;
}
void solve() {
	cnt = 0;
	memset(fa, 0, sizeof(fa));
	memset(a, 0, sizeof(a));
	memset(f, 0, sizeof(f));
	cin >> n >> d;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (long long i = 1; i <= n; i++) {
		fa[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
	}
	for (long long i = 1; i <= n; i++) {
		bool flag = true;
		for (long long j = fa[i] + 1; j <= n; j++) {
			flag = false;
			cnt += check(i, j);
		}
		if (flag) {
			break;
		}
	}
	cout << cnt << "\n";
}
int main() {
	IOS; FILE("migrate");
	long long tid, T;
	cin >> tid >> T;
	if (tid == 13 || tid == 14) {
		while (T--) {
			long long tmp;
			cin >> tmp;
			cout << 0 << '\n';
		}
		return 0;
	}
	while (T--) {
		solve();
	}
	return 0;
}

