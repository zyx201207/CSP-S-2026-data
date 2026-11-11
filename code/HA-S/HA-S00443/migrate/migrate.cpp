#include <bits/stdc++.h>
using namespace std;
int n,a[2000006],d;
int f[1005][1005];
int g[1005][1005];
long long ans;
void solve () {
	cin>>n>>d;
	ans = 0;
	for (int i = 1;i <= n;i ++) {
		cin>>a[i];g[i][i] = 1;
		for (int j = i + 1;j <= n;j ++) {
			f[i][j] = 1e9;
			g[i][j] = 0;
		}
	}
	for (int l = 2;l <= n;l ++) {
		for (int i = 1;i + l - 1 <= n;i ++) {
			int j = i + l - 1;
			int lf = i,rt = j - 1,k = j - 1;
			if (a[j] - a[j - 1] > d) continue;
			while (lf <= rt) {
				int mid = (lf + rt) / 2;
				if (a[j] - a[mid] <= d) {
					k = mid;
					rt = mid - 1;
				} else lf = mid + 1;
			}
			while (f[i][k] == 1e9) k ++;
			f[i][j] = f[i][k] + 1;
			for (int t = k;f[i][t] == f[i][k] && g[i][j] <= 2;t ++) {
				g[i][j] += g[i][t];
			}
			if (g[i][j] > 2) g[i][j] = 3;
			if (g[i][j] == 2) {
				ans ++;
//				cout<<i<<"--"<<j<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t --) solve();
	fclose (stdin);
	fclose (stdout);
	return 0;
}
