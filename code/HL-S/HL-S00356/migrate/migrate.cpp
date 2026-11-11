#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10, inf = 0x3f3f3f3f3f3f3f3f;

int n, d, a[N], r[N];

struct node { int mn, g; } tr[N << 2];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid (l + r) / 2

void pushup(node &a, node b, node c)
{
	if (b.mn < c.mn) a = b;
	else if (b.mn > c.mn) a = c;
	else a = { b.mn, b.g + c.g };
}

void update(int rt, int l, int r, int p, node v)
{
	if (l == r) return tr[rt] = v, void();
	if (p <= mid) update(ls, l, mid, p, v);
	else update(rs, mid + 1, r, p, v);
	pushup(tr[rt], tr[ls], tr[rs]);
}

node query(int rt, int l, int r, int sp, int ep)
{
	if (sp > ep) return { inf, 0 }; 
	if (sp <= l && r <= ep) return tr[rt];
	node res; bool f = 0;
	if (sp <= mid) res = query(ls, l, mid, sp, ep), f = 1;
	if (ep > mid) {
		auto t = query(rs, mid + 1, r, sp, ep);
		if (f) pushup(res, res, t);
		else res = t;
	}
	return res;
}

void solve()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n, j = n; i >= 1; i--) {
		while (j >= 1 && a[i] - a[j] <= d) j--;
		r[i] = j + 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 4 * n; j++) tr[j] = { inf, 0 };
		update(1, 1, n, i, { 0, 1 });
		for (int j = i + 1; j <= n; j++) {
			auto t = query(1, 1, n, r[j], j - 1);
			if (t.g == 2) ans++;
			t.mn++;
			update(1, 1, n, j, t);
		}
	}
	cout << ans << "\n";
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	cin.tie(0)->ios::sync_with_stdio(false);
	int c, t; cin >> c >> t;
	while (t--) solve();	
	return 0;
}