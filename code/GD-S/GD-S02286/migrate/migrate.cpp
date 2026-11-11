#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10, inf = 0x3f3f3f3f;

int a[N], d[N][N], f[6][6];
int n, o;

int getk(int i, int j) {
	int l = i + 1, r = j, mid;
	while(l < r) {
		mid = (l + r) >> 1;
		if(a[j] - mid <= o) r = mid;
		else l = mid + 1;
	}
	return l;
}

int getl(int i, int k, int j) {
	int l = k, r = j - 1, mid;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if(d[i][mid] + d[mid][j] == d[i][j]) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 

	int c, t;
	cin >> c >> t;
	while(t--) {
        cin >> n >> o;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) d[i][i] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1, k = i; j <= n; j++) {
				while(k < j && a[j] - a[k] > o) k++;
				if(k == j) d[i][j] = inf;
				else d[i][j] = 1 + d[i][k];
			}
		}
		for(int i = 1; i <= n - 1; i++) f[i][i + 1] = 1;
		for(int len = 2; len <= n; len++) {
			for(int i = 1, j = 1 + len; j <= n; i++, j++) {
				int k = getk(i, j), l = getl(i, k, j);
				f[i][j] = 0;
				if(k == j) continue;
				for(int x = k; x <= l; x++) {
					f[i][j] += f[i][x] * f[x][j];
				}
			}
		}

		int ans = 0;
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++) if(f[i][j] == 2) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

