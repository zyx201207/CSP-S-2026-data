#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, a[N], f[N], ans = -1;
vector<int> tmp;
void sear(int index, int step) {
	if (step == m) {
		if (f[index] != -1) { ans = max(f[index], ans); return; }
		int res = tmp[0];
		for (auto v : tmp) res &= v;
		ans = max(ans, res);
		f[index] = max(f[index], res);
		return;
	}
	for (int i = index; i <= n; i++) {
		tmp.push_back(a[i]);
		sear(i + 1, step + 1);
		tmp.pop_back();
	}
}
signed main() {
	fill(f, f + N, -1);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sear(1, 0);
	printf("%lld\n", ans);
	return 0;
}
