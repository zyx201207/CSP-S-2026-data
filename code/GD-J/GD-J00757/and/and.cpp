#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 114 + 514;
int a[N];
int num[2][N], tp, siz[2], n, m; 
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	siz[tp] = n;
	for(int i = 1; i <= n; i++) num[tp][i] = a[i];
	for(int i = 30; i >= 0; i--) {
		siz[tp ^ 1] = 0;
		for(int j = 1; j <= siz[tp]; j++) {
			if((num[tp][j] >> i) & 1) {
				siz[tp ^ 1]++;
				num[tp ^ 1][siz[tp ^ 1]] = num[tp][j];
			}
		}
		if(siz[tp ^ 1] >= m) {
			tp ^= 1;
		}
	}
	int res = INT_MAX;
	for(int i = 1; i <= m; i++) res = res & num[tp][i];
	cout << res;
	
	return 0;
} 
