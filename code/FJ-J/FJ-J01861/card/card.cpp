#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], s[N], c[N];
int b[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	} 
	for (int i = 1; i <= n; i ++ ) {
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		int cnt = i - 1;
		for (int j = i; j <= n; j ++ ) {
			if (!b[a[j]]) b[a[j]] = j;
			else {
				for (int k = b[a[j]]; k < j; k ++ ) {
					b[a[k]] = 0;
					c[ ++ cnt] = a[k];
				}
				b[a[j]] = j;
			}
		}
		for (int j = 1; j <= m; j ++ ) {
			if (b[j]) s[j] ++ ;
		}
		for (int j = i; j <= n; j ++ ) {
			if (b[a[j]] == j) {
				b[a[j]] = 0;
				c[ ++ cnt] = a[j];
			}
		}
		for (int j = i; j <= n; j ++ ) a[j] = c[j];
	}
	for (int i = 1; i <= m; i ++ ) cout << s[i] << ' ';
	return 0;
}
