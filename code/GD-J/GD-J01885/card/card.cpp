#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main ( ) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v1(m + 1, 0);
	vector<int> v2(m + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n; i++) {
			if (v1[a[i]] == 1) {
				for (int j = 1; j <= m; j++) {
					v1[j] = 0;
				}
			}
			v1[a[i]]++;
		}
		for (int i = 1; i <= m; i++) {
			v2[i] += v1[i];
			v1[i] = 0;
		} 
	}
	for (int i = 1; i <= m; i++) {
		cout << v2[i] << " ";
	}
	return 0;
}
