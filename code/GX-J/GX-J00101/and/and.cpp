#include <bits/stdc++.h>
using namespace std;

int n, m, a[200001], f[200001];

int _and(int* ar) {
	int rs = -1;
	for (int i = 1, j = ar[i]; i <= sizeof(ar) / sizeof(int); i++) 
		if (j % 2) rs &= j;
	return rs;
}

int w(int j) {
	int rs = a[j];
	for (int i = j; i <= n; i++) rs &= w(i);
	return rs;
}

int main() {
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << a[n] << endl;
	return 0;
}