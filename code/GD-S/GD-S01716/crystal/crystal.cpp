#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp(x, y) make_pair((x), (y))
#define pp pop_back
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define bk(x) x.back()
#define all(x) x.begin(), x.end()

const int N = 5e5 + 5;

int n;
ll m, a[N] = {0}, s[N] = {0}; 

ll ask(int l, int r) {
	if (l > r) return 0ll;
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j + 1 <= n && ask(i, j + 1) <= m) j++;
		ans = max(ans, j - i + 1);
	}
	printf("%d\n", ans);
	return 0;
} 
