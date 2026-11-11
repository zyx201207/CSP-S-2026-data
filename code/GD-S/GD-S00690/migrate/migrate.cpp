#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;

int n;
ll d;
ll a[maxn];
int mxto[maxn];
void init() {
	for (int i = 1; i <= n; i++) {
		mxto[i] = 0;
	}
}
bool work(int st, int ed, int tstep) {
	int step = 0, f = 0;
	for (int i = st; i < ed; i = mxto[i]) {
		step++;
	}
	return step + 1 == tstep;
}
// O(n^2)
inline void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int r = 1;
	for (int i = 1; i <= n; i++) {
		while (r < n && a[r + 1] - a[i] <= d) {
			r++;
		}
		mxto[i] = r;
	}
	ll ans = 0;
	for (int st = 1; st <= n; st++) {
		for (int ed = st + 1; ed <= n; ed++) {
			int step = 0, f = 0;
			for (int i = st; i < ed; i = mxto[i]) {
				if (mxto[i] == i) {
					f = 1;
					break;
				}
				step++;
			}
			if (f) break;
			int nstep = 0, lst = st;
			int cnt = 0;
			for (int i = st; i < ed; i = mxto[i]) {
				for (int j = lst + 1; j < i; j++) {
					cnt += work(j, ed, step - nstep);
				}
				lst = i;
				nstep++;
			}
			ans += (cnt == 2);
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int C, T;
	cin >> C >> T;
	while (T--) {
		init();
		solve();
	}
}
