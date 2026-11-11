#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

long long c, t;
long long n, a[N], m, b[N][2], y[3 * N][2];
long long x[N][N], xl[N];

long long dfs(long long z) {
	for (int i = 1; i <= n; i++) b[i][0] = 0;
	for (int i = 1; i <= n; i++) b[i][1] = N - 4;
	long long l = 1, r = 1;
	y[l][0] = z;
	y[l][1] = 1;
	b[z][0]++;
	
	while (l <= r) {
		long long cnt = y[l][0], cnt2 = y[l][1];
		l++;
		
		for (int i = xl[cnt]; i >= 1; i--) {
			if (b[x[cnt][i]][0] < 3 && b[x[cnt][i]][1] >= cnt2 + 1) {
				b[x[cnt][i]][0]++;
				b[x[cnt][i]][1] = cnt2 + 1;
				r++;
				y[r][0] = x[cnt][i];
				y[r][1] = cnt2 + 1;
			}
		}
	}
	
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		if (b[i][0] == 2) sum ++;
	return sum;
}

int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] <= m) x[i][++xl[i]] = j;
				else break;
			}
			
		long long sum = 0;
		for (int i = 1; i <= n; i++) sum += dfs(i);
		
		cout << sum << endl; 
		for (int i = 1; i <= n; i++) xl[i] = 0;
	}
	return 0;
}
