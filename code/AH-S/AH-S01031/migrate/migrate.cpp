/*CN*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 2e6 + 5;
int n, x[N], c, t, cnt, f[N], fl[N];
ll d,  minn = LLONG_MAX;
vector<int> a[N];
void search(int cur, int step, int goal) {
	if(cur == goal) {
		f[step]++;
		minn = min(minn, (ll)step);
		return;
	}
	for (int i = 0; i < (int)a[cur].size(); i++) {
		int dx = a[cur][i];
		if (fl[dx] == 0) {
			fl[dx] = 1;
			search(dx, step + 1, goal);
			fl[dx] = 0;
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		for (int i = 1; i <= n; i++) {
			f[i] = fl[i] = 0;
			a[i].clear();
		}
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (abs(x[i] - x[j]) <= d) {
					a[i].push_back(j);
				}
			}
		}
		for (int i = 1; i < n; i++) {
			fl[i] = 1;
			for (int j = i + 2; j <= n; j++) {
				minn = LLONG_MAX;
				search(i, 0, j);
				if(f[minn] == 2) {
					cnt++;
				}
				for (int k = 1;k <= n; k++) {
					f[k] = 0;
				}
			}
			fl[i] = 0;
		}
		cout << cnt << "\n";
	}
	return 0;
}
