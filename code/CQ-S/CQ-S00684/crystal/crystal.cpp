#include<bits/stdc++.h>
#define ls (x << 1)
#define rs (x << 1 | 1)
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int N = 5e5 + 5;
const db EPS = 1e-6;
const int MOD = 998244353;
const ull P = 33550337;

inline int lowbit(int x) {
	return (x & (-x));
}

ll n, m, a[N], ans;

int main() {
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	ll l = 1, r = 1, val = 0;
	for (; r <= n; r++) {
		ll len = r - l + 1;
		val += (len - 1) * (a[r] - a[r - 1]);
		while (val > m) {
			val -= a[r] - a[l];
			l++;
			len--;
		}
		ans = max(ans, len);
	}
	
	cout << ans;
	
	return 0;
}
