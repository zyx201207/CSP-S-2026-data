#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d, a[2000010], ans = 0, res = 0;
	cin >> c >> t;
	while(t --) {
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(abs(j - i) <= d) {
					ans ++;
					n -= j;
					j = j + 1;
				}
				if(n <= 0) break;
			}
			if(ans == 2) {
				res ++;
			}
		}
		cout << res << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
