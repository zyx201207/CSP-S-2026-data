// Life blooms like a flower,
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, ans;
long long m, a[N], s[N];

inline bool check(int l, int r) {
	int cnt = r - l + 1;
	long long res = a[r] * cnt - (s[r] - s[l - 1]);
	return res <= m;
}

int main() {
//	freopen("crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
