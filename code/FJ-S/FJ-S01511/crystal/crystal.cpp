#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

int n;
ll m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w" ,stdout);
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
	}
	
	sort(a + 1, a + n + 1);
	
	ll cost = 0;
	int l = 1, ans = 1;
	for (int i = 2; i <= n; ++i) {
		cost += (i - l) * (a[i] - a[i - 1]);
		while (cost > m) {
			cost -= a[i] - a[l++];
		}
		ans = max(ans, i - l + 1);
	}
	
	printf("%d", ans);
	return 0;
}

