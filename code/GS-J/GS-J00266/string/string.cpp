#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, ans;
struct node {
	int x;
	char c;
}a[N];
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n; 
	for (long long i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].c;
	}
	long long i = 1, l = n;
	while (a[i].x && a[l].x || a[i].x == a[l].x) {
		if (a[i].c != a[l].c) {
			ans += min (a[i].x, a[l].x);
		}
		a[i].x -= min (a[i].x, a[l].x);
		a[l].x -= min (a[i].x, a[l].x);
		if (a[i].x > a[l].x) {
			l--;
		}
		else if (a[i].x < a[l].x) {
			i++;
		}
		else {
			l--, i++;
		}
	}
	cout << ans;
	return 0;
}
