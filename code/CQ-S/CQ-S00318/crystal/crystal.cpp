#include<bits/stdc++.h>
#define int long long
#define mse(x, y) memset(x, y, sizeof(x))
#define mcp(x, y) memcpy(x, y, sizeof(x))
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define drep(x, r, l) for(int x = r; x >= l; x--)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 5e5 + 5;
int n, m, a[MAXN], ans = 1;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	FASTIO;
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, sum = 0;
	rep(i, 2, n){
		sum += (a[i] - a[i - 1]) * (i - l);
		while(l < i && sum > m) sum -= (a[i] - a[l]), l++;
		ans = max(ans, i - l + 1);
	} 
	cout << ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7


*/
