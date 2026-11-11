#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], dif[500005], lst[500005], ans[500005];
int t[500005];

void Sub1() {
	for (int i = 1; i <= n; i++) {
		if (i == n || a[i] != a[i + 1]) cout << i << ' ';
	}
}

void Sub() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dif[j] = 0;
		for (int j = 1; j <= m; j++) lst[j] = 0;
		for (int j = i; j <= n; j++) {
			if (lst[a[j]] && !t[lst[a[j]]]) {
				cout << j << '\n';
				for (int k = lst[a[j]]; k < j; k++) t[k] = 1;
			}
			lst[a[j]] = j;
		}
		for (int j = i; i <= n; i++) {
			if (!t[j]) ans[a[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
}

int main() {
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i != 1 && a[i - 1] > a[i]) flag = 0;
	}
	if (flag) Sub1();
	else Sub();
	return 0;
}
