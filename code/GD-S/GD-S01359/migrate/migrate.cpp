#include <bits/stdc++.h>
using namespace std;
using ULL = long long unsigned int;
const int N = 2e6 + 5;
int ct;
int temp;
void dfs(ULL* a, int idx, int end, ULL d, int dis) {
	if (idx == end) {
		if (dis == temp) ++ct;
		else if (dis < temp) {
			temp = dis;
			ct = 1;
		}
		return;
	}
	for (int i = idx + 1; a[i] - a[idx] <= d && i <= end; ++i) {
		dfs(a, i, end, d, dis + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	if (C <= 10) {
		int n, d;
		ULL a[20];
		int cnt;
		while (T--) {
			cin >> n >> d;
			for (int i = 1; i <= n; ++i) {
				cin >> a[i];
			}
			cnt = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 2; j <= n; ++j) {
					ct = 0;
					temp = INT_MAX;
					dfs(a, i, j, d, 0);
					if (ct == 2) ++cnt;
				}
			}
			cout << cnt << '\n';
		}
	} else if (C == 11 || C == 12) {
		int n, d;
		ULL a[N];
		int cnt;
		while (T--) {
			cin >> n >> d;
			for (int i = 1; i <= n; ++i) {
				cin >> a[i];
			}
			cnt = 0;
			for (int j = 4; j <= n; ++j) {
				ct = 0;
				temp = INT_MAX;
				dfs(a, 1, j, d, 0);
				if (ct == 2) cnt += n - j + 1;
				else if (ct > 2) break;
			}
			cout << cnt << '\n';
		}
	}
	return 0;
}

