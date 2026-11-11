#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10; 
int n, m, a[N], vis[N], ans;

signed main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 30; ~i; i--) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) 
			if(!vis[j]) cnt += (a[j] >> i) & 1;
		if(cnt >= m) {
			for(int j = 1; j <= n; j++)
				if(!((a[j] >> i) & 1)) vis[j] = 1;
			ans += (1ll << i); 
		}
	} cout << ans;
	return 0;
} // fc and.out and.ans
