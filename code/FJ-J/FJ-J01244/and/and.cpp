#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define PII pair<int, int>
const int N = 1000010;
const int inf = 1e18;
using namespace std;
int a[N];
bool vis[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	For(i, 1, n) cin >> a[i], vis[i] = 1;
	int ans = 0;
	Rof(j, 30, 0) {
		int cnt = 0;
		For(i, 1, n) {
			if(((a[i] >> j) & 1) && vis[i]) cnt ++;
		}
		if(cnt >= m) {
			For(i, 1, n) {
				if(!((a[i] >> j) & 1)) vis[i] = 0;
			}
			ans += (1 << j); 
		}
	}
	cout << ans;
	return 0;
}
