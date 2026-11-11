#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 1; 
int a[MAXN];
int num[300][300];
int n;
int d;
int pn;
int bg;
void f(int now) {
	if (now == a[n]) {
		num[pn][now]++;
		num[bg][now]++;
		return ;
	}
	num[pn][now]++;
	num[bg][now]++;
	pn = now;
	for (int i = 1; i <= d; i++) {
		f(now + i);
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			bg = a[i];
			f(bg);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j && num[i][j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
