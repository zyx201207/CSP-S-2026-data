#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 2;
const int M = 1e2 + 2;
const int INF = 0x3f3f3f3f;
int n, ans;
LL m, a[N], s[N];

bool Check(int mid, int i) {
	return 1LL * (i - mid + 1) * a[i] - (s[i] - s[mid - 1]) <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, bst = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (Check(mid, i)) {
				r = mid - 1, bst = mid;
			} else {
				l = mid + 1;
			}
		}
		if (~bst) {
			ans = max(ans, i - bst + 1);
		}
	}
	printf("%d", ans);
	return 0;
}
