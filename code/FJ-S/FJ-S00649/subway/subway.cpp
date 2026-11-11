#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
int c, n, m, d, q, k, x, y;
long long sum;
int w[500010], a[1005][1005];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	while(n --) {
		cin >> k;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= 2 * k; j ++) {
				cin >> a[i][j];
			}
		}
	}
	while(q --) {
		cin >> x >> y;
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= 2 * k; j ++) {
			if(a[i][j] == x) {
				sum += w[x] + a[i][j + 1];
			} 
			if(a[i][j] == y) {
				sum += w[y] + a[i][y + 1]; 
			}
		}
	}
	for(int i = 1; i <= q; i ++) {
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
