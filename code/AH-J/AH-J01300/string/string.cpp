#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 2;
const int M = 1e2 + 2;
const int INF = 0x3f3f3f3f;
int n, a[N], tot[26];
struct Segment {
	LL l, r;
} s[26][N];
LL m, ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char c;
		scanf("%d", &a[i]);
		cin >> c;
		s[c - 'a'][++tot[c - 'a']] = {m + 1, m + a[i]};
		m += a[i];
	}
	ans = m;
	for (int i = 0; i < 26; i++) {
		int p = tot[i];
		LL tmp = 0;
		for (int j = 1; j <= tot[i]; j++) {
			LL l = s[i][j].l, r = s[i][j].r;
			// Current segment.
			LL rl = m - r + 1, rr = m - l + 1;
			// Reversed segment.
			while (p >= 1 && s[i][p].r >= rl) {
				LL tl = s[i][p].l, tr = s[i][p].r;
				tmp += max(0LL, min(rr, tr) - max(rl, tl) + 1);
				p--;
			}
			if (p < tot[i] && s[i][p + 1].l < rl) {
				p++;
			}
//			printf("j=%d p=%d\n", j, p);
		}
		ans -= tmp;
	}
	printf("%lld", ans / 2);
	return 0;
}
