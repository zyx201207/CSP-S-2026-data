#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans[n] = {0};
	for (int i = n - 1; i > 0; i--) {
		int t = m, k = 0;
		for (int j = 0; j < n; j++) {
			if (a[i] == a[j] || i == j) continue;
			if (a[i] - a[j] >= 0 && a[i] - a[j] <= t) {
				ans[k++]++;
				t -= a[i] - a[j];
			}
			if (t == 0) break;
		}
	}
	int maxa = INT_MIN;
	for (int i = 0; i < n; i++)
		maxa = max(maxa, ans[i]);
	cout << maxa << "\n";
	return 0;
}
