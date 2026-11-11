#include<bits/stdc++.h>
using namespace std;
#define int long long //注意内存

//c++14
//多测清空
//边界
//复杂度

const int N = 2e6 + 6;
int a[N];
int f[305][305];
int cnt[305][305];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int c, t;
	cin >> c >> t;
	while(t--) {
		int n, d, ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if(c < 11) {
			memset(f, 0x3f, sizeof f);
			memset(cnt, 0, sizeof cnt);
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++) {
					if(abs(a[i] - a[j]) <= d)
						f[i][j] = 1, cnt[i][j] = 1;
					if(i == j)
						f[i][j] = 1, cnt[i][j] = 0;
				}
			for(int k = 1; k <= n; k++)
				for(int i = 1; i <= n; i++)
					for(int j = 1; j <= n; j++) {
						if(f[i][k] + f[k][j] < f[i][j])
							f[i][j] = f[i][k] + f[k][j], cnt[i][j] = cnt[i][k] * cnt[k][j];
						else if(f[i][k] + f[k][j] == f[i][j])
							cnt[i][j] += cnt[i][k] * cnt[k][j];
					}
			for(int i = 1; i <= n; i++)
				for(int j = i + 1; j <= n; j++)
					if(cnt[i][j] == 2)
						ans++;
			cout << ans << "\n";
		}
		else if(c == 11 || c == 12) {
			int p = a[2] - a[1];
			int tmp = d / p * 2 - 1;
			if(d < 2 * p)
				cout << 0 << "\n";
			else
				cout << max(n - tmp, 0ll) << "\n";
		}
	}
	
	return 0;
}
//I AK IOI

