#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6 + 10; 
inline int read(){
	int x = 0,f = 1; char c = getchar();
	while(c < '0' || c > '9')  {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar();
	}
	return x * f;
}
struct seg{
	vector <int> t, lzy;
	void build(int n) { t.resize(4 * n + 10, 0), lzy.resize(4 * n + 10, 0); }
	void rez(int n) { for(int i = 1;i < 4 * n + 10;i++) t[i] = lzy[i] = 0; }
	void pushdown(int p, int op) {
		if(t[p] && op == 1) t[p << 1] = t[p << 1 | 1] = t[p], t[p] = 0; 
		if(lzy[p] && op == 2) {
			lzy[p << 1] += lzy[p], lzy[p << 1 | 1] += lzy[p];
			t[p << 1] += lzy[p], t[p << 1 | 1] += lzy[p];
			lzy[p] = 0;
		}
	}
	void update(int p, int l, int r, int ql, int qr, int qx) {
		if(ql <= l && r <= qr) return t[p] = qx, void();
		else {
			int mid = (l + r) >> 1; pushdown(p, 1);
			if(ql <= mid) update(p << 1, l, mid, ql, qr, qx);
			if(qr > mid) update(p << 1 | 1, mid + 1, r, ql, qr, qx); 
		} 
	} 
	void update2(int p, int l, int r, int ql, int qr, int qx) {
		if(ql <= l && r <= qr) {
			lzy[p] += qx, t[p] += qx;
			return void();
		} else {
			int mid = (l + r) >> 1; pushdown(p, 2);
			if(ql <= mid) update2(p << 1, l, mid, ql, qr, qx);
			if(qr > mid) update2(p << 1 | 1, mid + 1, r, ql, qr, qx); 
			t[p] = t[p << 1] + t[p << 1 | 1];
		} 
	} 
	int query(int p, int l, int r, int qx) {
		if(qx == l && r == qx) return t[p];
		else {
			int mid = (l + r) >> 1; pushdown(p, 1);
			if(qx <= mid) return query(p << 1, l, mid, qx);
			else return query(p << 1 | 1, mid + 1, r, qx);
		}
	}
	int query2(int p, int l, int r, int qx) {
		if(qx == l && r == qx) return t[p];
		else {
			int mid = (l + r) >> 1; pushdown(p, 2);
			if(qx <= mid) return query2(p << 1, l, mid, qx);
			else return query2(p << 1 | 1, mid + 1, r, qx);
		}
	}
};
void solve() {
	int n, d; cin >> n >> d; vector <int> x(n + 10), lst(n + 10);
	for(int i = 1;i <= n;i++) cin >> x[i];
	for(int i = 1;i <= n;i++)
		lst[i] = upper_bound(x.begin() + i, x.begin() + n + 1, x[i] + d) - x.begin() - 1; 
//	for(int i = 1;i <= n;i++) cout << lst[i] << " "; cout << "\n";
	seg mn, dp; mn.build(n), dp.build(n); int ans = 0;
	vector <int> mn_to(n + 10); 
	for(int i = 1;i <= n;i++) {
//		puts("=========");
		int j = i; mn_to[0] = i;
		mn.rez(n), dp.rez(n);
		while(lst[j] != j) {
			int mn_j = mn.query(1, 1, n, j);
			mn.update(1, 1, n, j + 1, lst[j], mn_j + 1);
			mn_to[mn_j + 1] = lst[j];
			j = lst[j];
		} dp.update(1, 1, n, i, i, 1);
		for(int j = i;j <= n;j++) {
			int mn_id = mn.query(1, 1, n, j), dp_val = dp.query2(1, 1, n, j);
//			cout << j << " " << mn_id << " " << dp_val << " " << mn_to[mn_id] + 1 << " " << lst[j] << "\n";
			if(dp_val == 2) ans++;
			if(mn_to[mn_id] != n) {
				dp.update2(1, 1, n, mn_to[mn_id] + 1, lst[j], dp_val);
//				if(mn_to[mn_id] + 1 <= 4 && lst[j] >= 4) cout << j << " " << dp_val << "\n";
			}
		}
	}
	cout << ans << "\n";
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read(), t = read();
	while(t--) solve();
}

