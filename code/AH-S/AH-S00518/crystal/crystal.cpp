#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define irep(i, r, l) for (int i = r; i >= l; --i)
using namespace std;


const int N = 5e5 + 5;

long long a[N];
__int128 t[N], disc[N], buck[N];

void write (__int128 x) {
	if (x < 10) putchar (x + '0');
	else write (x / 10), putchar (x % 10 + '0');
}

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	long long n, m, ans;
	__int128 tm, req, num, add, dst, tmp, lcur, len;
	cin >> n >> m;
	rep (i, 1, n) cin >> a[i], disc[i] = a[i];
	sort (disc + 1, disc + 1 + n), len = unique (disc + 1, disc + 1 + n) - disc - 1;
	rep (i, 1, n) a[i] = lower_bound (disc + 1, disc + 1 + len, a[i]) - disc, ++buck[a[i]];
	ans = buck[1], lcur = 0, req = 0, num = add = 0;
	rep (i, 2, len) {
		tm = m - (disc[i] - disc[i - 1]) * buck[i - 1];
		if (tm <= 0) {
			ans = max ((__int128)ans, buck[i] + m / (disc[i] - disc[i - 1])), lcur = i - 1;
			num = add = m / (disc[i] - disc[i - 1]), req = num * (disc[i] - disc[i - 1]); 
			continue;
		}
		req += add * (disc[i] - disc[i - 1]);
		while (tm < req) {
			dst = disc[i] - disc[lcur];
			if (req - tm > num * dst) req -= num * dst, add -= num, num = buck[lcur + 1], ++lcur; 
			else tmp = (req - tm - 1) / dst + 1, req -= tmp * dst, num -= tmp, add -= tmp;
		}
		ans = max ((__int128)ans, add + buck[i] + buck[i - 1]), req += (disc[i] - disc[i - 1]) * buck[i - 1], add += buck[i - 1]; 
	}
	cout << ans << endl;
	return 0;
}
