#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	long long a[int(2e5) + 5];
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	if(m == 1) {
		long long maxa = -1;
		for (int i = 1;i <= n;i ++) {
			maxa = max(maxa, a[i]);
		}
		cout << maxa;
		return 0;
	} else if (m == 2) {
		long long maxa = -1;
		for (int i = 1;i < n;i ++) {
			for (int j = i + 1;j <= n;j ++) {
				maxa = max(maxa, a[i] & a[j]);
			}
		}
		cout << maxa;
		return 0;
	} else if (m == n) {
		long long andsum = a[1];
		for (int i = 2;i <= n;i ++) {
			andsum &= a[i];
		}
		cout << andsum;
		return 0;
	} else {
		long long maxas = -1;
		for (int k = 1;k <= n;k ++){
			long long maxa = a[k], maxpos = k;
			bool vis[int(2e5) + 5] = {0};
			vis[k] = 1;
			for (int i = 2;i <= m;i ++) {
				long long tmaxa = -1;
				for (int j = 1;j <= n;j ++) {
					if(!vis[j]) {
						if(int(maxa & a[j]) > tmaxa) {
							tmaxa = maxa & a[j];
							maxpos = j;
						}
					}
				}
				vis[maxpos] = 1;
				maxa = tmaxa;
			}
			maxas = max(maxas, maxa);
		}
		cout << maxas;
		return 0;
	}
}
