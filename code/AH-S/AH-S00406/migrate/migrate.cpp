	#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, tt, n, d;
const int N = 2e6 + 10, inf = 1e18;
// int f[2][N], g[N];
int pre[N], suf[N];
int a[N];
typedef pair <int, int> pii;
pii f[N];
// struct bit {
// 	int tr[N << 1];
// 	void reset() {
// 		for (int i = 1; i <= (n << 1); i ++) tr[i] = 0;
// 	}
// 	int lowbit(int x) {
// 		return (x & (- x));
// 	}
// 	void add(int x, int v) {
// 		while(x <= n) {
// 			tr[x] += v;
// 			x += lowbit(x);
// 		}
// 	}
// 	int query(int x) {
// 		int res = 0;
// 		while (x) {
// 			res += tr[x];
// 			x -= lowbit(x);
// 		}
// 		return res;
// 	}
// 	int req(int x) {
// 		return query(n) - query(x - 1);
// 	}
// } t;
struct seg {
	struct node {
		int v;
		int ls, rs;
	} tr[N * 25];
	int cnt = 0;
	void pushup(int u) {
		tr[u].v = tr[tr[u].ls].v + tr[tr[u].rs].v;
	}
	void build() {
		while (cnt) {
			tr[cnt] = {0, 0, 0};
			cnt --;
		}
	}
	void modify(int &u, int l, int r, int pos, int v) {
		if(!u) {
			u = (++ cnt);
			tr[u] = {0, 0, 0};
		}
		if(l == r) {
			tr[u].v += v;
			return ;
		}
		int mid = l + r >> 1;
		if(pos <= mid) modify(tr[u].ls, l, mid, pos, v);
		else modify(tr[u].rs, mid + 1, r, pos, v);
		pushup(u);
	}
	pii query(int u, int l, int r) {
		if(!u) return make_pair(inf, 0);
		if(l == r) return make_pair(l, tr[u].v);
		int mid = l + r >> 1;
		if(tr[tr[u].ls].v) return query(tr[u].ls, l, mid);
		return query(tr[u].rs, mid + 1, r);
	}
} t;
int root;
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		// f[0][i] = f[1][i] = g[i] = 0;
		pre[i] = i;
		suf[i] = i;
	}
	int p = 1;
	for (int i = 1; i <= n; i ++) {
		while (p <= i && a[i] - a[p] > d) p ++;
		pre[i] = p;
	}
	p = n;
	for (int i = n; i > 0; i --) {
		while (p >= i && a[p] - a[i] > d) p --;
		suf[i] = p;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		f[i] = {0, 1};
		root = 0;
		t.build();
		t.modify(root, 0, inf, 0, 1);
		int nl = i;
		for (int j = i + 1; j <= n; j ++) {
			while (nl < pre[j]) {
				t.modify(root, 0, inf, f[nl].first, (- f[nl].second));
				nl ++;
			}
			pii now = t.query(root, 0, inf);
			f[j] = now;
			f[j].first ++;
			t.modify(root, 0, inf, f[j].first, f[j].second);
		}
		for (int j = i + 1; j <= n; j ++) {
			if(f[j].second == 2) ans ++;
		}
	}
	cout << ans << endl;
	// t.reset();
	// for (int i = 1; i <= n; i ++) {
	// 	if(pre[i] < i) {
	// 		if(pre[pre[i] + 1] - 1 >= pre[pre[i]] - 1) f[0][i] = max(0ll, t.query(pre[pre[i] + 1] - 1) - t.query(pre[pre[i]] - 1));
	// 		f[0][i] += max(0ll, pre[pre[i] + 1] - 1 - pre[pre[i]] + 1);
	// 		f[0][i] += (i - pre[i]);
	// 	}
	// 	if(pre[i] < i - 1) {
	// 		if(pre[pre[i] + 2] - 1 >= pre[pre[i] + 1] - 1) f[1][i] = max(0ll, t.query(pre[pre[i] + 2] - 1) - t.query(pre[pre[i] + 1] - 1));
	// 		f[1][i] += max(0ll, pre[pre[i] + 2] - 1 - pre[pre[i] + 1] + 1);
	// 	}
	// 	t.add(i, f[0][i]);
	// }
	// t.reset();
	// for (int i = n; i > 0; i --) {
	// 	if(suf[i] > i) {
	// 		if(suf[suf[i] - 1] + 1 <= suf[suf[i]] + 1) g[i] = max(0ll, t.req(suf[suf[i] - 1] + 1) - t.req(suf[suf[i]] + 1));
	// 		g[i] += max(0ll, suf[suf[i]] - (suf[suf[i] - 1] + 1) + 1);
	// 		g[i] += (suf[i] - i);
	// 	}
	// 	t.add(i, g[i]);
	// }
	// int ans = 0;
	// for (int i = 1; i <= n; i ++) {
	// 	cerr << f[0][i] << ' ' << f[1][i] << ' ' << g[i] << endl;
	// 	ans += (g[i] + 1) * f[1][i];
	// }
	// cout << ans << endl;
}
signed main(void) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> tt;
	if(c >= 11 && c <= 12) {
		while (tt --) {
			cin >> n >> d;
			for (int i = 1; i <= n; i ++) {
				cin >> a[i];
				// f[0][i] = f[1][i] = g[i] = 0;
				pre[i] = i;
				suf[i] = i;
			}
			int p = 1;
			for (int i = 1; i <= n; i ++) {
				while (p <= i && a[i] - a[p] > d) p ++;
				pre[i] = p;
			}
			p = n;
			for (int i = n; i > 0; i --) {
				while (p >= i && a[p] - a[i] > d) p --;
				suf[i] = p;
			}
			int lp = 0, rp = 0;
			for (int i = 1; i <= n; i ++) {
				if(pre[i] == 1 && suf[i] == n) {
					lp = i;
					break ;
				}
			}
			for (int i = 1; i <= n; i ++) {
				if(pre[i] == 1 && suf[i] == n) {
					rp = i;
				}
			}
			if(rp - lp + 1 > 2) {
				cout << 0 << endl;
				continue ;
			}
			int ans = 0;
			for (int i = 1; i < lp; i ++) {
				if(suf[i] > rp + 1) continue ;
				if(rp - lp + 1 == 2 && suf[i] > rp) continue ;
				if(suf[i] > rp) {
					ans += suf[suf[i]] - suf[lp - 1];
				}
				else {
					if(rp - lp + 1 == 1 && i < lp - 1) {
						ans += suf[lp - 1] - suf[lp - 2];
					}
					if(rp - lp + 1 == 2) {
						ans += n - suf[lp - 1];
					}
				}
			}
			cout << ans << endl;
		}
		return 0;
	}
	if(c >= 13 && c <= 14) {
		while (tt --) {
			cin >> n >> d;
			for (int i = 1; i <= n; i ++) cin >> a[i];
			if(n == 1) {
				cout << 0 << endl;
				continue ;
			}
			int del = a[2] - a[1];
			int can = d / del;
			if(can <= 1) {
				cout << 0 << endl;
				continue ;
			}
			int ans = 0;
			for (int i = 1; i <= n; i ++) {
				if(i + can + can - 1 <= n) ans ++;
			}
			cout << ans << endl;
		}
		return 0;
	}
	while (tt --) solve();
	return 0;
}