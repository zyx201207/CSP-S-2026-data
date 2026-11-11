//100 pts
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
const int MaxN = 5e5;

int n; ll m;
ll a[1 + MaxN];
ll sum[1 + MaxN];
bool check (int i, int idx) {
	return (idx - i + 1)*a[idx] - (sum[idx] - sum[i - 1]) <= m;
}
int binsearch (int l, int r, int idx) {
	int res = r;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid, idx)) {
			res = mid;
			r = mid - 1;
		}else {
			l = mid + 1;
		}
	}
	return res;
}
int ans;

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {scanf("%lld", &a[i]);}
	sort(&a[1], &a[n] + 1);
	for (int i = 1; i <= n; ++i) {sum[i] = sum[i - 1] + a[i];}
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, i - binsearch(1, i, i) + 1);
	}
	printf("%d\n", ans);
	return 0;
}