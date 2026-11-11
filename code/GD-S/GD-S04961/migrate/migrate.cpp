#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;

int test_num, t;
int n, d;
int x[N];

bool sp_A = 1;

int minn = INT_MAX, cnt = 0;

void dfs(int now, int end, int p) {
	if (p - 1 > minn) return;
	if (now >= end) {
		if (p - 1 < minn) cnt = 1, minn = p - 1;
		else if (p - 1 == minn) cnt++;
		return;
	}
	if (now > end) return;	
	for (int i = 1; i <= d; ++i) {
		if (now + i <= end) {
			dfs(now + i, end, p + 1);
		}
	}
}

bool check(int x, int y) {
	int t = 0;
	minn = INT_MAX;
	cnt = 0;
	dfs(x, y, 1);
	if (cnt == 2) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> test_num >> t;
	while (t--) {
		cin >> n >> d;
		x[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
			if (i > 1 && x[i] - x[i - 1] != 1) sp_A = 0;
		}
		if (sp_A) {
			int t = 0;
			for (int i = 1; i <= n - 1; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					if (check(i, j)) t++;
				}
			}
			cout << t << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
} 

