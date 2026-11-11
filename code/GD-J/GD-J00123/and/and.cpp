#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
int ans = -1;

void f (int pos, int cnt, int temp) {
	if (cnt == m + 1) {
		ans = max(ans, temp);
		return ;
	}
	for (int i = pos; i <= n; i++) {
//		int l = a[i] & temp;
//		cout << a[i] << " " << temp << "=" << l << " " << pos << " " << cnt << "\n";
		f(i + 1, cnt + 1, a[i] & temp);
	}
}

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	f(1, 1, pow(2, 31) - 1);
	cout << ans;
	return 0;
}
//5 3
//31 3 1 15 7
