#include <bits/stdc++.h>

using namespace std;

int dfs(vector<int> v, int n, int m) {
	if (m == 1) {
		int max = 0;
		for (int i = 1; i <= n; i++) {
			if (v[i] > max) {
				max = v[i];
			}
		}
		cout << max;
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i] = v[i] & v[j];
			}
		}
		for (int i = 1; i <= n * (n + 1) / 2; i++) {
			cout << v[i];
		}
		m--;
		dfs(v, n * (n + 1) / 2, m);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1, 0);
	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		v[i] = a;
	}
	for (int i = 1; i <= n; i++) {
		cout <<v[i] <<endl;
	}
	dfs(v, n, m);

	return 0;
} 
