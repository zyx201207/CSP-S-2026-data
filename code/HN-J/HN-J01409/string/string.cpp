#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, a[N], sum, tot1, tot2, ans;
char c[N];
struct Node {
	int l, r;
	char ch;
}p[N][2];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int mid = sum / 2 + (sum & 1), pre = 0;
	for (int i = 1; i <= n; i ++) {
		pre += a[i];
		if (pre >= mid) {
			int val = pre - mid;
			p[++ tot1][0] = {1, a[i] - val, c[i]};
			p[++ tot2][1] = {1, val + (sum & 1), c[i]};
			mid = i;
			break;
		}
	}
	for (int i = mid - 1; i >= 1; i --) {
		p[++ tot1][0] = {p[tot1 - 1][0].r + 1, p[tot1 - 1][0].r + a[i], c[i]};
	}
	for (int i = mid + 1; i <= n; i ++) {
		p[++ tot2][1] = {p[tot2 - 1][1].r + 1, p[tot2 - 1][1].r + a[i], c[i]};
	}
	int p2 = 1, l1 = 1, t = 1;
	for (int i = 1; i <= tot1; i ++) {
		while (p[p2][1].l <= p[i][0].r && t <= p[i][0].r) {
			ans += (p[i][0].ch != p[p2][1].ch) * (min(p[i][0].r, p[p2][1].r) - t + 1);
			t = min(p[i][0].r, p[p2][1].r) + 1;
			if (p[p2][1].r <= p[i][0].r) p2 ++;
		}
	}
	cout << ans;
	return 0;
}
