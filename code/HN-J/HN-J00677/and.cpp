#include <bits/stdc++.h>;
using namespace;

int n = 0;
int m = 0;
int a[10086] = 0;
int MAX = 0;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i <= n; i++){
		int a0 = 0;
		cin >> a0;
		a[i] = a0;
	}
	for (int i = 0;i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j) return 0;
			MAX = max(MAX, (a[i] & a[j]));
		}
	}
	cout << MAX;
}
