#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[200010];
	int sum = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= m; i ++) {
		sum = a[i] & a[i + 1];
	}
	cout << sum << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
