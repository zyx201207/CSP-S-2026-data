#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n + 5);
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	if(m == 1) {
		cout << n;
	} else {
		vector<int> dat(n + 1, 0);
		vector<int> ans1(n + 1, 0);
		for (int i = 1;i <= n;i ++) {
			for (int p = i;p <= n;p ++) {
				dat[p] = a[p];
			}
			for (int p = 1;p < i;p ++) {
				dat[p] = 0;
			}
			for (int j = i;j <= n;j ++) {
				for (int k = i;k < j;k ++) {
					if(dat[k] == a[j]) {
						for (int l = k;l < j;l ++) {
							dat[l] = 0;
						}
					}
				}
			}
			bool h[int(3e5+5)] = {0};
			for (int j = 1;j <= m;j ++) {
				for (int k = i;k <= n;k ++) {
					if(dat[k] == j) {
						h[j] = 1;
					}
				}
			}
			for (int j = 1;j <= m;j ++) {
				if(h[j]) ans1[j] ++;
			}
		}
		for (int i = 1;i <= m;i ++) {
			cout << ans1[i] << " ";
		}
		return 0;
	}
}
