#include <bits/stdc++.h>
using namespace std;
int a[500005], cnt[300005];
bool bj[500005];
int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (bj[a[j]]) {
				int k = j - 1;
				while (a[k] != a[j]) {
					bj[a[k--]] = false;
				}
			}
			else bj[a[j]] = true;
		}
		for (int j = 1; j <= m; j++) {
			if (bj[j]) {
				cnt[j]++;
			}
		}
		memset (bj, 0, sizeof(bj)); 
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}
