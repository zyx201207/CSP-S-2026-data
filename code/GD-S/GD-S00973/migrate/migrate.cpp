#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int c, t;
int n, d;
int x[N];
int f[N];

/*
 * 17:16
 * wo yi jing jue wang le.
 * ti dou kan bu tai dong. bao li dou da bu liao...
 * hai you ren lei ma?
 *
 * GnRH
 */

int main() { // Oct31==Dec25
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		//unordered_map<int, bool> mp;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[j] = 0;
			}
			f[i] = 1;
			for (int j = 1; j < i; j++) {
				if (x[i] - x[j] <= d) {
					f[j] += f[i];
					//cout << f[i] << ' '<< f[j] << endl;
				}
			}
			for (int i = 1; i <= n; i++) {
				ans += (f[i] == 2);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
