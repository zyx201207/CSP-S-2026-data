#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500001], flag[500001], ans[500001];
bool book[500001];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= n - 1; j++) {
			if (book[a[j]] == 1) {
				for (int k = flag[a[j]]; k <= j; k++)
					book[k] = 0;
			}
			book[a[j]] = 1;
			flag[a[j]] = j;
		}
		for (int l = 1; l <= m; l++)
			if (book[l])
				ans[l]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}