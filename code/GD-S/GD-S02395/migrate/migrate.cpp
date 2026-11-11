#include<iostream>
#include<algorithm>
#define ll long long
#define N 1000005
using namespace std;

ll c, t, a[N], nxt[N];
ll const INF = 1e18;
ll n, d, l, r, ans;
inline void init() {
	ans = 0;
}

bool check()  {
	ll pos = l, cnt = 0;
	while(nxt[pos] != pos && pos < r) {
		ll lst = pos;
		pos = nxt[pos];
		if(pos > r) pos = r;
		if(pos == r) break;
//		for(ll i = lst + 1; i < pos; i++) {
//			if(pos != r && min(nxt[i], r) == min(nxt[pos], r)) cnt++;
//			if(cnt > 1) return 0;
//		}
		ll idx = lower_bound(nxt + lst, nxt + pos, min(nxt[pos], r)) - (nxt);
//		cout << lst << " " << pos << " " << idx << endl;
		cnt += pos - idx;
		if(cnt > 1) return 0;
	}
	if(pos < r) return 0;
//	cout << cnt << endl;
	return cnt == 1;
}

inline void solve() {
	init();
	cin >> n >> d;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	
	for(ll i = 1; i <= n; i++) 
		nxt[i] = upper_bound(a + 1, a + 1 + n, a[i] + d) - (a + 1);
		
//	for(ll i = 1; i <= n; i++) cout << nxt[i] << " ";
//	cout << endl;
	
//	l = 2, r = 5;
//	cout << check() << endl;
	
//	l = 1, r = 1;
//	while(l <= r && l <= n && r <= n) {
//		if(r - l + 1 <= 3) {
//			r++;
//			continue;
//		}
//		while(check() && l <= r) {
//			ans++;
//			l++;
//		}
//		r++;
//	}

//	for(l = 1; l <= n - 3; l++) {
//		for(r = l + 3; r <= n; r++)  {
//			if(check()) {
//				ans++;
//			}
//		}
//	}

	for(r = 4; r <= n; r++) for(l = 1; l <= r - 3; l++) {
		if(check()) {
			ans++;
		}
	}
	
	cout << ans << endl;
}

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	while(t--) solve();

	cout.flush();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 3
0 3 6 7 8 9 10 13 16 19

0 1
6 4
-3 0 1 2 3 4
*/

