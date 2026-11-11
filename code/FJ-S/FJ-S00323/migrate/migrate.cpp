#include <bits/stdc++.h>
using namespace std;

int C, T;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d %d", &C, &T);
while (T--) {
	int n, d; 
	scanf("%d %d", &n, &d);
	long long x[2000005];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x[i]);
	}
	int mu2v[2000005][2000005] = {};
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n; j++) {
			if (x[j] - x[i] <= d) mu2v[i][j]++;
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 2; j < n; j++) {
			mu2v[i][j]
		}
	}
}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

