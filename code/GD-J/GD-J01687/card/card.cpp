#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200010], sum[200010];
int num[200010], len;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		len = 0;
		for(int j = i; j <= n; j++) {
			for(int k = 1; k <= len; k++) {
				if(num[k] == a[j]) {
					len = k - 1;
					break;
				}
			}
			num[++len] = a[j];
		}
		for(int j = 1; j <= len; j++) {
			sum[num[j]] ++;
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << sum[i] << ' ';
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
