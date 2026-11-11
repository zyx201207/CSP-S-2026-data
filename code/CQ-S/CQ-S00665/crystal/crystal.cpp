#include<bits/stdc++.h>
#define rep(i, x, y) for(int i = (x); i <= (y); ++i)
#define drep(i, x, y) for(int i = (x); i >= (y); --i)
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) (A).begin(), (A).end()
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using i64 = long long;
template<typename T> inline void cmax(T &x, const T &y) { x = (x < y ? y : x); }
template<typename T> inline void cmin(T &x, const T &y) { x = (x < y ? x : y); }
const int N = 5e5 + 5;
int n, ans = 1;
i64 a[N], m, s[N];
inline i64 W(int l, int r) {
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]);
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	fastio, cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	for(int i = n, j = i; i; --i) {
		while(j > 1 && W(j - 1, i) <= m) --j;
		cmax(ans, i - j + 1); 
	}
	cout << ans << '\n'; 
	return 0;
}
