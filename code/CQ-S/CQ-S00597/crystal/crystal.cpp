#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
int n;
ll m, a[N];

bool check(int l, int r) {
	ll sum = 0;
	for (int i = l; i <= r; i++)
		sum += a[r] - a[i];
	return sum <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = i, r = n;
		while(l < r) {
			int m = (l + r + 1) / 2;
			if (check(i, m)) l = m;
			else r = m - 1;
		}
		ans = max(ans, l - i + 1);
	}
	cout << ans << '\n';
}
