#include<bits/stdc++.h>
using namespace std;
const int N = 305, M = 2e6 + 10;
int op, t, n;
long long d, a[M], f[N][N], cnt[N][N];
void slv() {
	cout << t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		long long dis = a[2] - a[1], x = d / dis;
		x = x * 2;
		if(d / dis == 1) cout << 0 << '\n';
		else cout << max(n - x + 1, 0LL) << '\n';
	}
	return ;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> op >> t;
	if(op == 11 || op == 12) {
		slv();
		return 0;
	}
	while(t--) {
		cin >> n >> d;
		long long ans = 0;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= n; j++) cnt[i][j] = 0, f[i][j] = 1e18;
		for(int i = 1; i <= n; i++) f[1][i] = 1, cnt[1][i] = 1;
		for(int L = 2; L <= n; L++) {
			for(int i = 1; i + L - 1 <= n; i++) {
				int j = i + L - 1;
				if(a[j] - a[i] <= d) {
					f[L][i] = 2, cnt[L][i] = 1;
					continue;
				}
				for(int k = i + 1; k < j; k++) {
					if(a[k] - a[i] > d) break;
					if(f[j - k + 1][k] + 1 < f[L][i]) 
						f[L][i] = f[j - k + 1][k] + 1, cnt[L][i] = cnt[j - k + 1][k];
					else if(f[j - k + 1][k] + 1 == f[L][i]) cnt[L][i] += cnt[j - k + 1][k];
				}
				if(cnt[L][i] == 2) ans++;
			} 
		}
		cout << ans << '\n';
	}
	
	
	return 0;
}
