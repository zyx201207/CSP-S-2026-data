#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 500005
#define coi const int &

struct node {
	int cnt;
	ll val;
};

int n;
ll m, a[N], s[N];
int ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", & n, & m);
	for (int i = 1; i <= n; scanf("%lld", & a[i ++]));
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; s[i] = s[i - 1] + a[i], ++ i);
	for (int i = 1; i <= n; ++ i) {
		int l = 0, r = i, j = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if ((i - mid) * a[i] - (s[i] - s[mid]) <= m) {
				j = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - j);
	}
	printf("%d\n", ans);
	return 0;
}
