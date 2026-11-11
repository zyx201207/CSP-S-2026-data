#include <bits/stdc++.h>
#define f first
#define s second
#define put make_pair
using namespace std;
typedef pair<int, int> PII;
const int N = 1e4 + 5;
int c, T;
int n, d;
int x[N];
int dp[N];
bool vis[N];
int res;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		res = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int st = 1; st <= n; st++) {
			for (int fi = st + 1; fi <= n; fi++) {
				memset(vis, 0, sizeof vis);
				memset(dp, 0 ,sizeof dp);
				bool f = false;
				for (int i = st + 1; i <= fi; i++) {
					if (x[i] - x[i - 1] > d) {
						f = true;
						break;
					}
				}
				if (f) break;
				int la = st, fa = st;
				for (int i = 1; i <= n; i++) {
					if (abs(x[i] - x[st]) <= d) dp[i] = 1, fa = max(fa, i);
				}
				la = fa;
				while(dp[fi] == 0) {
					for (int i = la + 1; i <= n; i++) {
						if (abs(x[i] - x[la]) > d) {
							fa = i - 1;
							break;
						}
						dp[i] = dp[la] + 1;
					}
					la = fa;
				}
				int mi = 0x7ffffff, cn = 0;
				for (int i = 1; i <= n; i++) {
					if (abs(x[i] - x[fi]) <= d) mi = min(mi, dp[i]);
				}
				for (int i = 1; i <= n; i++) if (abs(x[i] - x[fi]) <= d && mi == dp[i]) cn++;
				if (cn == 2) res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}
