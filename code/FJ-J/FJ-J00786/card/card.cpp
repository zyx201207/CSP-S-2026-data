#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
bool cmp(int x, int y) {
	return x < y;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[500010], b[500010];
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	b[1] = a[1];
	for(int i = 1; i <= n; i ++) {
			if(a[i] != b[1]) {
				b[i] = a[i];
				i ++;
			} else {
				b[1] = a[i];
			}
	}
	for(int i = 1; i <= m; i ++) {
		cout << b[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
