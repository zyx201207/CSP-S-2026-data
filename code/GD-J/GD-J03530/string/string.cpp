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
	fre("string")
	ios
	int n;
	cin >> n;
	vector<int>a(n + 1);
	vector<char>b(n + 1);
	For(i, 1, n) cin >> a[i] >> b[i];
	ll len = 0;
	For(i, 1, n) len += a[i];
	ll len2 = (len + 1) / 2;
	ll sum = 0, id = 0;
	ll ans = 0;
	int l = id, r = id + 1;
	For(i, 1, n) {
		sum += a[i];
		if (sum > len2) {
			id = i;
			ll sub1 = sum - len2, sub2 = len2 - sum + a[i] - 1;
			if (sub1 < sub2) a[i] -= sub1 * 2, l = id, r = id + 1;
			else a[i] -= sub2 * 2, l = id - 1, r = id; 
			if (len % 2) a[i]--;
			break;
		}
	}
	while (l >= 1 && r <= n) {
		if (a[l] > a[r]) {
			if (b[l] != b[r]) ans += a[r];
			a[l] -= a[r];
			r++; 
		} else {
			if (b[l] != b[r]) ans += a[l];
			a[r] -= a[l];
			l--; 
		}
	}
	cout << ans << endl;
}
