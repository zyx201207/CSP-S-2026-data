#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e3 + 10;
int n,m,a[N];bool vis[N][N];

signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	auto t1 = clock();
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		for (int j = 1;j <= i;j++) {
			if (vis[j][a[i]]) {
				for (int k = i - 1;k >= j;k--) {
					if (a[k] == a[i]) {
						break;
					}
					vis[j][a[k]] = false;
				}
			} else {
				vis[j][a[i]] = true;
			}
		}
	}
	for (int i = 1;i <= m;i++) {
		int sum = 0;
		for (int j = 1;j <= n;j++) {
			sum += (vis[j][i] ? 1 : 0);
		}
		cout << sum << " ";
		cerr << sum << " ";
	}
	cout << endl;
	cerr << endl;
	auto t2 = clock();
	cerr << t2 - t1 << " ms" << endl;
	return 0;
}