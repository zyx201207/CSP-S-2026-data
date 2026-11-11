#include<bits/stdc++.h>
using namespace std;
#define ll long long

int const N = 5005;
int f[N][N], c, t, n, d, x[N], cnt[N][N];

void init() {
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) f[i][i] = 0, cnt[i][i] = 1;
}

void solve() {
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			for(int k = j; k >= i; k--) {
				if(x[j] - x[k] > d) continue;
				if(f[i][k] + 1 < f[i][j]) {
					f[i][j] = f[i][k] + 1;
					cnt[i][j] = cnt[i][k]; 
				}else if(f[i][k] + 1 == f[i][j]) cnt[i][j] += cnt[i][k];
			}
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		init();
		solve();
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(cnt[i][j] == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

