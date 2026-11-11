#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 100;
int a[M];
int ans[M];
int res[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int l = 0, r = 0;
		for (int j = i; j <= n; j++) {
			for (int k = max(i, l); k < j; k++) {
				if (a[k] == a[j]) {
					l = j - 1; r = 0;
					break;
				}
			}
			r++;
			ans[l + r] = a[j];
		}
		for (int i = l + 1; i <= r + l + 1; i++) {
			res[ans[i]]++;
		}
		memset(ans, 0, sizeof(ans));
	}	
	for (int i = 1; i <= m; i++)
		cout << res[i] << " ";
	cout << "\n";	
	return 0;
} 
