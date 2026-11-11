#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e3 + 7, inf = 0x3f3f3f3f;
struct Info {
	ll mn, cnt;
	Info operator + (const Info &o) const {
		Info rtn;
		int mnn = min(mn, o.mn);
		rtn.mn = mnn, rtn.cnt = (mn == mnn ? cnt : 0) + (o.mn == mnn ? o.cnt : 0);
		return rtn;
	}
}; 
struct SegTree {
	Info sgt[maxn * 4];
	void build(int u, int l, int r) {
		if(l == r) {
			sgt[u].mn = inf, sgt[u].cnt = 0;
			return;
		}
		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		sgt[u] = sgt[u << 1] + sgt[u << 1 | 1];
	}
	void update(int u, int l, int r, int id, int x1, int x2) {
		if(l == r) {
			sgt[u].mn = x1, sgt[u].cnt = x2;
			return;
		}
		int mid = (l + r) >> 1;
		if(id <= mid) update(u << 1, l, mid, id, x1, x2);
		else update(u << 1 | 1, mid + 1, r, id, x1, x2);
		sgt[u] = sgt[u << 1] + sgt[u << 1 | 1];
	}
	Info query(int u, int l, int r, int s, int t) {
		if(s <= l && r <= t) return sgt[u];
		int mid = (l + r) >> 1;
		if(t <= mid) return query(u << 1, l, mid, s, t);
		if(s > mid) return query(u << 1 | 1, mid + 1, r, s, t);
		return query(u << 1, l, mid, s, t) + query(u << 1 | 1, mid + 1, r, s, t);
	}
} sgt;
ll a[maxn];
int seg[maxn], dis[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t; cin >> c >> t;
	while(t--) {
		
		int n; ll d; cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		int l = 1;
		for(int i = 1; i <= n; i++) {
			while(a[i] - a[l] > d) l++;
			seg[i] = l;
		}
		
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			sgt.build(1, 1, n);
			dis[i] = 0; sgt.update(1, 1, n, i, 0, 1);
			for(int j = i + 1; j <= n; j++) {
				int l = max(i, seg[j]);
				Info tmp = sgt.query(1, 1, n, l, j);
				if(tmp.cnt == 2) ans++;
				dis[j] = tmp.mn + 1;
				sgt.update(1, 1, n, j, dis[j], tmp.cnt);
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}
