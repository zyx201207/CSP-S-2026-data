#include<bits/stdc++.h> 
#define int long long
#define f(i, s, e) for(int i = s; i <= e; ++i)
#define dw(i, e, s) for(int i = e; i >= s; --i)
#define pii pair<int, int>
using namespace std;

int c, t, n, d, a[2000005], nxt[2000005], lt[200005], pre[2000005], ans;
int dp[305];

void pls(){
	f(i, 1, n){
		f(j, i, n) dp[j] = 0;
		dp[i] = 1;
		f(j, i + 1, n){
			int k = j - 1;
			while(a[j] - a[k] >= d && k) dp[j] += dp[k], --k;
			if(dp[j] >= 3) break;
			ans += (dp[j] == 2);
		}
	}
}

void pla(){
	int db = a[2] - a[1];
	int t = d / db;
	ans = max(0ll, n - 2 * t + 1);
}

void solve(){
	cin >> n >> d; ans = 0;
	f(i, 1, n) cin >> a[i];
	if(n <= 2){
		cout << "0\n";
		return ;
	}
	if(c <= 10) pls();
	if(11 <= c && c <= 12) pla();
	cout << ans << "\n";
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
