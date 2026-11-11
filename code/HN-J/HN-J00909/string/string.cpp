#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, a[N];
char c[N];
long long ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> c[i];
	int i = 1, j = n;
	while (i < j) {
		if (a[i] < a[j])
			ans += a[i] * (c[i] != c[j]), a[j] -= a[i ++];
		else
			ans += a[j] * (c[i] != c[j]), a[i] -= a[j --];
	}
	cout << ans;
	return 0;
}













/*
剑旗爵，是我赢了
凯撒，恕我直言，我没看出来你哪赢了
爱卿请看，五枚黑子已经连成一条直线了，是我赢了
？？？
后面忘了
*/
