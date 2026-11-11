#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 5e5 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[N];
ll up[N];
ll down[N];
ll last[N];
ll go[N];

bool is = true;
bool is2;
bool is3;
ll n, m, op, p;
ll sum, ans1, ans2, now1, now2, ans, l, r, now , maxx;

int main () {
	cin.tie (0) -> sync_with_stdio (0);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > a[i - 1] && i != 1) is2 = true;
		if (a[i] > maxx) {
			maxx = a[i];
			p = i;
		}
	}
	for (int i = 2; i <= n - 1; i++) {
		if (a[i] - a[i - 1] != a[i + 1] - a[i]) {
			is = false;
			break;
		}
	}
	for (int i = 2; i <= n; i++) {
		now1 += (a[i] - a[i - 1]) * (i - 1);
		if (now1 > m) {
			ans1 = i - 1;
			break;
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		now2 += (a[i] - a[i + 1]) * (n - i);
		if (now2 > m) {
			ans2 = n - i;
			break;
		}
	}
	if (is) {
		if (is2) cout << ans1 ;
		else cout << ans2 ;
		return 0;
	}
	sort (a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		if (a[i] == a[i + 1]) go[i] = go[i + 1];
		else go[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) last[i] = last[i - 1];
		else last[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		ans1 = 1, now = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (a[j] == a[j - 1] && j != 1) {
				if (now + (j - last[j] + 1) * (a[i] - a[j]) <= m) {
					now += (j - last[j] + 1) * (a[i] - a[j]);
					ans1 += (j - last[j] + 1);
					j = last[j];
					continue;
				}
			}
			if (now + a[i] - a[j] <= m) {
				now += a[i] - a[j];
				ans1++;
			}
		}
		ans = max (ans1, ans);
	}
	cout << ans ;
//	cout << " " << a[2066] << " " << a[4962] << endl;
}
