#include<bits/stdc++.h>
using namespace std;
int n, m;
int ans[10];
int a[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		ans[a[i]] += i;
		for(int j = n; j >= i; j--) {
			for(int k = i; k < j; k++) {
				if(a[j] == a[k]) {
					for(int p = k; p <= j; p++) {
						ans[a[j]] -= 1;
					}
				}
			}
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
