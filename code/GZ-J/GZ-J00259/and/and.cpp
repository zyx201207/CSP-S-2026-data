//GZ-J00259  白鹭湖小学 陈彦宇
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, maxn = INT_MIN, cnt = 0;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (long long i = 2; i <= n; i++) {
		maxn = max(maxn, (a[i] & a[i - 1]));
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

