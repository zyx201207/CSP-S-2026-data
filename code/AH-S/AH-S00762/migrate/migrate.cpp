#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long x[N];
int cnt = 0;
int n;
long long d;
long long minsteps = N;

void dfs(int now, int target, int steps) {
	if (now == target) {
		if (steps < minsteps) {
			minsteps = steps;
			cnt = 1;
		} else if (steps == minsteps) {
			cnt++;
		}
		return;
	}
	for (int i = now + 1; i <= target; i++) {
		if (x[i] - x[now] <= d) {
			dfs(i, target, steps + 1);
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		bool A = true;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			if (i >= 3 && x[i] - x[i - 1] != x[i - 1] - x[i - 2]) {
				A = false;
			}
		}
		if (x[n] - x[1] <= d) {
			cout << 0 << endl;
			continue;
		}
		if (A == true) {
			long long diff = x[2] - x[1];
			if (d < diff) {
				cout << 0 << endl;
				continue;
			}
			long long jump = d / (diff);
			if (jump == 1) {
				cout << 0 << endl;
				continue;
			}
			long long spa = jump * 2;
			cout << n - spa + 1 << endl;
		} else {
			
			long long ans = 0;
			for (int i = 1; i <= n - 3; i++) {
				for (int j = i + 3; j <= n; j++) {
					cnt = 0;
					minsteps = n + 1;
					dfs(i, j, 0);
					if (cnt == 2) {
						ans++;
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
