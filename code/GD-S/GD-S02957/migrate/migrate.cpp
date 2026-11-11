#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e3 + 10;

int c, t;
int x[N];
int dp[N][N], num[N][N], last[N];
void solve() {
	memset(dp, 0, sizeof(dp));
	memset(num, 0x3f, sizeof(num));
	memset(last, 0x3f, sizeof(last));
	int n, d, cnt = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++)
		cin >> x[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if(x[j] - x[i] <= d) {
				num[i][j] = 1;
				last[j] = min(last[j], i);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			for(int k = last[i]; k < i; k++) {
				num[j][i] = min(num[j][k] + num[k + 1][i], num[j][i]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)  {
			if(num[i][j] == 2) cnt ++; 
		}
	}
	
	cout << cnt << endl;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),	cout.tie(0);
	
	cin >> c >> t;
	while(t--) {
		solve();
	}
	
}
