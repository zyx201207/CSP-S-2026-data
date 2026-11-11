#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], c[N], ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		memset(c, 0, sizeof c);
		for (int j = i; j <= n; j++) {
			if (c[a[j]]) {
				for (int k = i; k < j; k++)
					if (c[a[k]])
						c[a[k]]--;
			} else
				c[a[j]]++;
		}
		for (int j = 1; j <= m; j++)
			if (c[j])
				ans[j]++;
	}
	for (int j = 1; j <= m; j++)
		cout << ans[j] << ' ';
	return 0;
}

