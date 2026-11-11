# include<bits/stdc++.h>

# define low(x) (x & - x)
# define int long long

using namespace std;

const int N = 2000005;

int c, T;
int n, d, ans;
int x[N], nxt[N], lst[N], sum[N];

int tr[N];
inline void add(int x, int v) {
	for (int i = x; i <= n; i += low(i))
		tr[i] += v;
}

inline int ask(int x) {
	int res = 0;
	if (x == 0) return res;
	for (int i = x; i; i -= low(i))
		res += tr[i];
	return res;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);

	cin >> c >> T;
	while (T --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++)
			cin >> x[i];
		for (int i = 1; i <= n; i ++) {
			int l = i, r = n, mid = 0;
			while (l < r) {
				mid = (l + r + 1) >> 1;
				if (abs(x[mid] - x[i]) <= d) l = mid;
				else r = mid - 1;
			}
			nxt[i] = l;
			l = 1, r = i, mid = 0;
			while (l < r) {
				mid = (l + r) >> 1;
				if (abs(x[mid] - x[i]) <= d) r = mid;
				else l = mid + 1;
			}
			lst[i] = l;
		}
		if (c == 11 || c == 12) {
			int tot = 0;
			ans = 0;
			for (int i = 1; i <= 1; i ++) {
				int now = nxt[i];
				for (int j = 1; j <= n; j ++) tr[j] = 0;
				for (int j = i + 1; j <= n; j ++) {
					if (j <= now) {
						sum[j] = 1;
						add(j, sum[j]);
						continue;
					}
					sum[j] = ask(now) - ask(lst[j] - 1);
					add(j, sum[j]);
					if (sum[j] == 2) ans ++;
					if (nxt[now] == j) now = j;
					tot += ans;
				}
			}
			cout << tot << "\n";
		} else {
			ans = 0;
			for (int i = 1; i <= n; i ++) {
				int now = nxt[i];
				for (int j = 1; j <= n; j ++) tr[j] = 0;
				for (int j = i + 1; j <= n; j ++) {
					if (j <= now) {
						sum[j] = 1;
						add(j, sum[j]);
						continue;
					}
					sum[j] = ask(now) - ask(lst[j] - 1);
					add(j, sum[j]);
					if (sum[j] == 2) ans ++;
					if (nxt[now] == j) now = j;
				}
			}
			cout << ans << "\n";
		}
	}

	return 0;
}