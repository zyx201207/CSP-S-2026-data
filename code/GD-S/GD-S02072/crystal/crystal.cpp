#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10;
int n, m;
int ans = 0, sum = 0;
int a[maxn];
signed main() {
    freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int x = 1;
	for (int i = 2;i <= n;i ++) {
		sum += (i - 1 - x) * (a[i] - a[i - 1]);
		while (1) {
			if (sum <= m) {
				break;
			}
			x ++;
			sum -=(a[i] - a[x - 1]);
			ans = max(ans, i - x + 1);
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
