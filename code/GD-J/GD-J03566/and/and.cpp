#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
ll a[N] = { };

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	ll ans;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	ans = a[1];
	for (int i = 1; i <= m; i++) 
		ans &= a[i];
	cout << ans;
	return 0;
} 
