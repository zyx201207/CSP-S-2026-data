#include <bits/stdc++.h> 
#define ll long long
#define ls o << 1
#define rs o << 1 | 1
using namespace std;
const ll N = 1e6 + 10;
/*struct tree{
	ll l, r, s, lz, len;
}tr[N];
void b(ll l, ll r, ll o) {
	tr[o].l = l, tr[o].r = r, tr[o].len = (r - l + 1);
	if (l == r) return;
	ll mid = (l + r) / 2;
	b(l, mid, ls);
	b(mid + 1, r,  rs);
	return;
}
void pushdown(ll o) {
	if (!tr[o].lz) return;
	tr[ls].s += tr[o].lz * tr[ls].len, tr[rs].s += tr[o].lz * tr[rs].len, tr[ls].lz += tr[o].lz, tr[rs].lz += tr[o].lz;
	tr[o].lz = 0;
	return;
}
void update(ll l, ll r, ll o) {
	if (tr[o].l >= l && tr[o].r <= r) {
		tr[o].s += tr[o].len, tr[o].lz++;
		return;
	}
	pushdown(o);
	ll mid = (tr[o].l + tr[o].r) / 2;
	if (mid >= l) update(l, r, ls);
	if (mid < r) update(l, r, rs);
	return;
}
ll query(ll pos, ll o) {
	if (tr[o].l === tr[o].r) return tr[o].s;
	pushdown(o);
	ll mid = (tr[o].l + tr[o].r) / 2;
	if (mid >= pos) return query(pos, ls);
	else return query(pos, rs);
}*/
ll n, m, ans[N], a[N], vis[N], b[N], top, tt;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		top = 0, tt = 0;
		for (int j = i; j <= n; j++) {
			vis[a[j]] = 0;
		}
		for (int j = i; j <= n; j++) {
			if  (vis[a[j]]) {
				for (int k = vis[a[j]] + 1; k <= top; k++) vis[b[k]] = 0;
				top = vis[a[j]];
			}else b[++top] = a[j], vis[a[j]] = top;
		}
		for (int j = 1; j <= top; j++) ans[b[j]]++;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
