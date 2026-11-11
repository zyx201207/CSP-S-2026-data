#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, m, k, sum;
ll a[N];
ll qpow(ll a, ll b) {
	ll sum = 1LL;
	while (b) {
		if ((b & 1LL)) sum = sum * a;
		a *= a;
		b >>= 1LL;
	}
	return sum;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	sum = a[n - m];
	for (int i = n - m + 1; i < n; ++i)
		sum &= a[i];
	cout << sum;
	return 0;
}