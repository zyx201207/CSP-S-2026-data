#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= (int)y; i++)
#define foR(i, x, y) for (int i = x; i >= (int)y; i--)
#define fin(x) freopen(x, "r", stdin);
#define fou(x) freopen(x, "w", stdout);
#define fre(x) fin(x".in") fou(x".out")
#define ios cin.tie(0) -> sync_with_stdio(false);
#define itn int
#define tin int
#define tni int
#define nit int
#define nti int
#define imnt int
#define inmt int
using ll = long long;
using lll = __int128_t;
using namespace std;
int a[500005];
int main() {
	fre("crystal")
	ios
	int n, m;
	cin >> n >> m;
	For(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, ans = 1, sum = 0, r = 1;
	while (r <= n) {
		sum += (a[r + 1] - a[r]) * (r - l + 1);
		r++;
		while (sum > m) {
			sum -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}
