#include <bits/stdc++.h>
using namespace std;
int cha(int a, int b) {
	if (a > b)
		return (a - b);
	else
		return (b - a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n+5] = {}, fc[n+5][n+5] = {}, fc_i = 0, ans;
	long long fc_h = 9223372036854775800;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	for (int i = 1; i <= n; i++) {
		int i_fc_h = 0;
		for (int j = 1; j <= n; j++) {
			fc[i][j] = cha(a[i], a[j]);
			i_fc_h += fc[i][j];
		}
		if (fc_h > i_fc_h) {
			fc_h = i_fc_h;
			fc_i = i;
		}
	}
	int min_fc[n+5] = {};
	for (int i = 1; i <= n; i++) {
		min_fc[i] = fc[fc_i][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (min_fc[j] > min_fc[j+1]) {
				int l = min_fc[j];
				min_fc[j] = min_fc[j+1];
				min_fc[j+1] = l;
			}
		}
	}
	int crystal_average = a[fc_i];
	for (int i = 2; i <= n; i++) {
		if (m >= min_fc[i]) {
			m -= min_fc[i];
			ans++;
		}
		else
			break;
	}
	cout << ans;
	return 0;
}
