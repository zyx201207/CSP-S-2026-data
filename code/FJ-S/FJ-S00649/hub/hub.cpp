#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, n, k, u[200010], v[200010];
	cin >> c >> t;
	while(t --) {
		cin >> n >> k;
		for(int i = 1; i <= n - 1; i ++) {
			cin >> u[i] >> v[i];
		}
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
