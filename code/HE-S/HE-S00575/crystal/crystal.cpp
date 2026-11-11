#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 5;
ll n, m, a[N], d[N], ans, t1, t2 = 1;
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort (a + 1, a + 1 + n);
	for (int i = 2; i <= n; i ++)
		d[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i ++) {
//		cout << ans << ' ' << t1  << ' ' << t2 << "     ";
		if (d[i] * (i - t2) + t1 <= m) {
			t1 = d[i] * (i - t2) + t1;
			ans = max(ans, i - t2 + 1);
//			cout << "x ";
		}
		else{
			while (d[i] * (i - t2) + t1 - (a[i] - a[t2]) > m && t2 <= i) {
				t1 -= (a[i - 1] - a[t2]);
				t2 ++;
			}
			t1 = d[i] * (i - t2) + t1 - (a[i] - a[t2]);
			t2 ++;
			ans = max(i - t2 + 1, ans);
//			cout << "y ";
		}
//		cout << ans << ' ' << t1  << ' ' << t2 << endl;
	}
	cout << ans;
	return 0;
}
