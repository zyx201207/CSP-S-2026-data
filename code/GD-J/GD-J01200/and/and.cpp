#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int ans, n, m, a[N];
vector <int> b[31];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int k = 30; k >= 0; k--) {
			if ((a[i] & (1 << k))) b[k].push_back(a[i]);
		}
	}
	for (int k = 30; k >= 0; k--) {
		if (int(b[k].size()) >= m) { 
			ans += (1 << k);
			for (int j = k - 1; j >= 0; j--) b[j].clear();
			for (int j = 0; j < int(b[k].size()); j++) {
				for (int i = 0; i < k; i++) {
					if ((b[k][j] & (1 << i))) b[i].push_back(b[k][j]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
