#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e6 + 5;

char c[N];
int n, a[N], m, len, k;

struct Seg {
	int l, r; char c;
} b[N], seg[N];

signed main ()
{	
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);

	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i], len += a[i];
		if (i != 1 && c[i] == c[i - 1]) b[m].r += a[i];
		else m++, b[m] = {b[m - 1].r + 1, b[m - 1].r + a[i], c[i]};
	}
	 
	if (len & 1) {
		int mid = (len + 1) >> 1;
		for (int i = 1; i <= m; i++) {
			if (mid >= b[i].l && mid <= b[i].r) {
				if (b[i].l == b[i].r) continue;
				else if (b[i].l == mid) seg[++k] = {mid + 1, b[i].r, b[i].c};
				else if (b[i].r == mid) seg[++k] = {b[i].l, mid - 1, b[i].c};
				else seg[++k] = {b[i].l, mid - 1, b[i].c}, seg[++k] = {mid + 1, b[i].r, b[i].c};
			} else seg[++k] = b[i];
		}
		int l = 1, r = k, ans = 0;
		while (l <= n) {
			if (seg[l].l >= mid) break;
			int lenl = seg[l].r - seg[l].l + 1, lenr = seg[r].r - seg[r].l + 1;
			if (lenl == lenr) {
				ans += (seg[l].c == seg[r].c ? 0 : lenl);
				l++, r--;
			} else if (lenl < lenr) {
				ans += (seg[l].c == seg[r].c ? 0 : lenl);
				l++, seg[r].r -= lenl;
			} else if (lenl > lenr) {
				ans += (seg[l].c == seg[r].c ? 0 : lenr);
				r--, seg[l].l += lenr;
			}
		}
		cout << ans << "\n";
	} else {
		int mid = (len >> 1);
		for (int i = 1; i <= m; i++) {
			if (mid >= b[i].l && mid <= b[i].r) {
				if (b[i].l == b[i].r || b[i].r == mid) seg[++k] = b[i];
				else seg[++k] = {b[i].l, mid, b[i].c}, seg[++k] = {mid + 1, b[i].r, b[i].c};
			} else seg[++k] = b[i];
		}
		int l = 1, r = k, ans = 0;
		while (l <= n) {
			if (seg[l].l > mid) break;
			int lenl = seg[l].r - seg[l].l + 1, lenr = seg[r].r - seg[r].l + 1;
			if (lenl == lenr) {
				ans += (seg[l].c == seg[r].c ? 0 : lenl);
				l++, r--;
			} else if (lenl < lenr) {
				ans += (seg[l].c == seg[r].c ? 0 : lenl);
				l++, seg[r].r -= lenl;
			} else if (lenl > lenr) {
				ans += (seg[l].c == seg[r].c ? 0 : lenr);
				r--, seg[l].l += lenr;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
