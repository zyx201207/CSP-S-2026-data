#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, d = 0;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int flag = 0, p[n], jz = j;
			for (int k = j; k < n; k++) {
				for (int l = k - 2; l >= jz; l--) {
					if (p[l] == a[k]) {
						flag = 0;
						jz = k;
					}
				}
				if (a[k] == i) {
					flag = 1;
				}
				p[k] = a[k]; 
			}
			if (flag) cnt ++;
		}
		cout << cnt << ' ';
	}
	return 0;
}
