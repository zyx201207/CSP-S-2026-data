#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 5e5 + 5;
int n, ans; ll a[N], S[N], m;
int main() {
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) S[i] = S[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int lo = 1, hi = i - 1; while (lo < hi) {int md = (lo + hi) >> 1; (i - md) * a[i] - (S[i - 1] - S[md - 1]) <= m ? hi = md : lo = md + 1;}
		ans = max(ans, i - hi + 1);
	}
	cout << ans;
	return 0;
}