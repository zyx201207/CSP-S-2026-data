#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int n, m, a[500010], sum, res;
bool cmp(int x, int y) {
	return x < y;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	int mid = (a[1] + a[n]) / 2;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i ++) {
		if(a[i] <= mid) {
			m -= mid - a[i];
			res ++;
		}
	}
	cout << res << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
