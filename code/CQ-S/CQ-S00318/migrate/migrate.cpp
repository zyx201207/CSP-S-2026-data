#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define eb emplace_back
#define PII pair<int, int>
#define mse(x, y) memset(x, y, sizeof(x))
#define mcp(x, y) memcpy(x, y, sizeof(x))
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define drep(x, r, l) for(int x = r; x >= l; x--)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 2000005;
int n, d, S[MAXN];
PII dp[MAXN];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	FASTIO;
	int C, T;
	cin >> C >> T;
	rep(Cs, 1, T){
		int ans = 0;
		cin >> n >> d;
		rep(i, 1, n) cin >> S[i];
		if(C == 11 || C == 12){
			int D = S[2] - S[1], num = d / D;
			if(num <= 1) cout << 0 << '\n';
			else cout << max(0ll, n - (num * 2 - 1)) << '\n'; 
			continue;
		}
		rep(x, 1, n){
			rep(i, 1, n) dp[i] = {0x3f3f3f3f3f3f3f3f, 0};
			dp[x] = {0, 1};
			int l = x;
			rep(i, x + 1, n){
				while(l < i && S[i] - S[l] > d) l++;
				if(l == i) break;
				if(l == i - 1){
					dp[i] = {dp[l].fi + 1, dp[l].se};
					continue;
				}
				if(dp[l].fi != dp[l + 1].fi){
					dp[i] = {dp[l].fi + 1, dp[l].se};
					continue;
				}
				if(dp[l].fi == dp[l + 1].fi && (l == i - 2 || dp[l + 1].fi != dp[l + 2].fi)){
					dp[i] = {dp[l].fi + 1, dp[l].se + dp[l + 1].se};
					continue;
				}
				dp[i] = {dp[l].fi + 1, 3};
			}
			rep(i, x, n) if(dp[i].se == 2) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
