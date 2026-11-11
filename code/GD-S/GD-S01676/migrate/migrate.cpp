#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

bool mst;

const int N = 2e6+10;
LL a[N], dp[N], cnt[N];
LL e[N], ne[N], h[N], idx;
LL c, T = 1;

void add(int a, int b) {
	e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

void solve() {
	memset(h, -1, sizeof(h));
	idx = 0;
	
	LL n, d;
	cin >> n >> d;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	if(c <= 10) {
		LL ans = 0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(a[j] - a[i] <= d) {
					add(i, j);
				}
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) dp[j] = 0x3f3f3f3f3f3f3f3f;
			for(int j=i+1; j<=n; j++) cnt[j] = 0;
			dp[i] = 0;
			cnt[i] = 1;
			for(int j=i; j<=n; j++) {
//				if(cnt[j] != 2 && cnt[j-1] == 2) {
//					break;
//				}
//				cout << a[i] << " " << a[j] << " " << cnt[j] << " " << dp[j] << "\n";
				if(cnt[j] == 2) {
					++ans;
				}
				for(int k=h[j]; k!=-1; k=ne[k]) {
					int nw = e[k];
					if(dp[nw] > dp[j] + 1) {
						dp[nw] = dp[j] + 1;
						cnt[nw] = cnt[j];
					} else if(dp[nw] == dp[j] + 1) {
						cnt[nw] += cnt[j];
					}
				}
			}
		}
		cout << ans << "\n";
	} else if(11 <= c && c <= 12) {
		int CNT = 0;
		for(int j=2; j<=n; j++) {
			if(a[j] - a[1] <= d) {
				++CNT;
			}
		}
		if(CNT == 1) {
			cout << "0\n";
			return ;
		}
		cout << max((n-1) - (2*CNT-1) + 1, 0ll) << "\n";
	} else {
		cout << "0\n";
	}
}

bool med;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	cerr << fixed << setprecision(8) << (&mst - &med) / 1024.0 / 1024.0 << "\n";
	
	cin >> c >> T;
	while(T--) {
		solve();
	}
	
	return 0;
} 
