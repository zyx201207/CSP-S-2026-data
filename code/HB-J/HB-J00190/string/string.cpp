#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 5;
ull n, a[N], dif;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	ull i = 1, j = n;
	while (i < j) {
		dif += min(a[i], a[j]) * (c[i] == c[j] ? 0 : 1);
		if (a[i] < a[j]) {
			a[j] -= a[i];
			i++;
		}
		else if (a[i] > a[j]){
			a[i] -= a[j];
			j--;
		}
		else i++, j--;
	}
	cout << dif;
	return 0;
}