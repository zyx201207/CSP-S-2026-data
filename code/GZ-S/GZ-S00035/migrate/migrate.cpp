// GZ-S00035 贵阳市白云区华师一学校 袁子高 
#include <bits/stdc++.h>
using namespace std;

int min_path = INT_MAX, ans_sum = 0;

void dfs(const vector<int>& dis, int d,int s, int e, int sum_dis = 0) {
	if (s == e) {
		if (min_path > sum_dis) {
			min_path = sum_dis;
			ans_sum = 1;
		} else if (min_path == sum_dis) {
			ans_sum++;
		}
		return;
	}
	for (int i = s + 1; i < e + 1 && dis[i] - dis[s] <= d; i++) {
		dfs(dis, d, i, e, sum_dis + 1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<int> dis(n);
		for (int i = 0; i < n; i++) {
			cin >> dis[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				min_path = INT_MAX;
				ans_sum = 0;
				dfs(dis, d, i, j);
				if (ans_sum == 2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
