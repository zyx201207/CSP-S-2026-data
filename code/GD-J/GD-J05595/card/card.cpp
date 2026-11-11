#include <bits/stdc++.h>
using namespace std;
int a1[500010], b[500010], c[300010], a[500010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a1[i];
	}
	for (int h = 1; h <= n; h++) {
		int l = 0;
		for (int i = 1; i <= n; i++) {
			if (h <= i) a[i] = a1[i];
			else a[i] = 0;	
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i] == b[j]) {
					for (int z = j; z <= n; z++) {
						if (b[z] != 0) l--;
							b[z] = 0;
						}
						break;
				}
			}
			b[l + 1] = a[i];
			l++;
			cout << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << endl;
		}
		for (int i = 1; i <= l; i++) c[b[i]]++;
	}
	for (int i = 0; i < m; i++) cout << c[i + 1] << " ";
	return 0;
}
