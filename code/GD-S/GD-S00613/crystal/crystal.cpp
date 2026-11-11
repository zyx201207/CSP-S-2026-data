// A crystal: 1s 1,024MiB. ORANGE-YELLOW.

using namespace std;
#include <iostream>
#include <algorithm>

const int maxn = 5e5+5;
long long a[maxn], s[maxn];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	int ans = 0, pos = 1;
	for (int i = 1; i <= n; i++) {
		while ((i - pos + 1) * a[i] - (s[i] - s[pos - 1]) > m) pos++;
		ans = max(ans, i - pos + 1);
	}
	cout << ans << endl;
	return 0;
}
