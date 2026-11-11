#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= (int)y; i++)
#define foR(i, x, y) for (int i = x; i >= (int)y; i--)
#define fin(x) freopen(x, "r", stdin)
#define fou(x) freopen(x, "w", stdout)
#define fre(x) fin(x".in"); fou(x".out");
#define ios cin.tie(0) -> sync_with_stdio(false);
#define itn int
#define tin int
#define tni int
#define nti int
#define nit int
#define imnt int
#define inmt int
using ll = long long;
using lll = __int128_t;
using namespace std;
int main() {
	fre("and")
	int n, m;
	cin >> n >> m;
	vector<int>a(n + 1);
	For(i, 1, n) cin >> a[i];
	ll ans = 0;
	foR(i, 30, 0) {
		ll bit = 1 << i, cnt = 0;
		For(j, 1, n) if ((a[j] & (bit | ans)) == (bit | ans)) cnt++;
		if (cnt >= m) ans |= bit;
	}
	cout << ans;
}
