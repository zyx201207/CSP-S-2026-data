#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n, m, x[N];
vector<int> a[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		int pos = 0, tmp = x[i];
		while (tmp) {
			if (tmp % 2 != 0) a[pos].push_back(i);
			tmp /= 2;
			++pos;
		}
	}
	int ans = 0;
	for (int i = 28; i >= 0; i--) {
		if (a[i].size() >= m) {
			ans += (1 << i);
//			cout << i << "\n"; 
			vector<int> tmp;
			for (int j : a[i]) tmp.push_back(j);
			for (int j = 0; j <= 28; j++) a[j].clear();
			for (int j : tmp) {
				int pos = 0, X = x[j];
				while (X) {
					if (X % 2 != 0) a[pos].push_back(j);
					X /= 2;
					++pos;
				}
			}
		}
	} 
	cout << ans;
	return 0;
}
