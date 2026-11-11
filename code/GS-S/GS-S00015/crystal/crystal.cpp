#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500100] = {0}, ma = -10E18 - 100, mi = 10E18 + 100, afterNum;

int check(int x) {
	long long sum = 0;
	afterNum = 0;
	for (int i = 0; ; i++) {
		if (a[i] > x) break;
		afterNum++;
		sum += x - a[i];
		if (sum > m) return -1;
	}
	if (sum < n) return 1;
	if (m == sum) return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > ma) ma = a[i];
		if (a[i] < mi) mi = a[i];
	}
	sort(a, a + n);
	
//	cout << ma << " <-ma    mi-> " << mi << '\n';
//	cout << "a(after sort): ";
//	for (long long i = 0; i < n; i++) cout << a[i] << ' ';
//	cout << '\n';
	
	long long l = mi, r = ma, mid, k;
	while (l < r) {
		mid = (l + r) / 2;
		k = check(mid);
		if ((l == mid && k > 0) || (r == mid && k < 0)) break;
		if (k == 0) { cout << afterNum << '\n'; return 0; }
		if (k > 0) l = mid;
		else r = mid;
	}
	cout << afterNum << '\n';
	
	return 0;
}

/*
#1
5 5
1 2 4 8 9

#2
5 8
-3 -1 2 2 7
*/
