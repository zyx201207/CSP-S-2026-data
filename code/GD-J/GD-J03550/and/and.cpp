#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
const int N = 1e6 + 10;
int a[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	
	cout << a[1];
}
