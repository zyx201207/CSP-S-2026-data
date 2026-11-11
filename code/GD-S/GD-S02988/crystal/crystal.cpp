#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10; 
ll a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1); 
	ll add = 0, mx = 1, cnt = 1;
	for (int i = 2; i <= n; i++) {
		add += 1LL * (a[i] - a[i - 1]) * cnt;
		cnt++;
		while (add > m) {
			cnt--;
			add -= a[i] - a[i - cnt];
		}
		mx = max(mx, cnt);
	}
	printf("%lld\n", mx);
	return 0;
}
