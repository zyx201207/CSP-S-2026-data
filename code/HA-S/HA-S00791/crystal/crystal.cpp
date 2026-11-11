#include<bits/stdc++.h>
#define LL long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define i128 __int128
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define fi first
#define se second
using namespace std;

const int N = 5e5 + 10;
int n, ans;
LL m, a[N], b[N];
/*
不一定从头填到尾！！！ 
*/

void solve() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	LL lst = 0;
	rep(i, 1, n) {
		LL nw = a[i], delta = nw - lst;
		LL tot = delta * (i - 1); //同一数值的情况 
		b[i] = b[i - 1] + tot;
		lst = nw;
	}
	rep(i, 1, n) {
		int l = 0, r = i, cnt = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(b[i] - b[mid] - 1ll * (mid - 1) * (a[i] - a[mid]) <= m) r = mid - 1, cnt = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - cnt + 1);
	}
	cout << ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int TIME1 = clock();
	solve();
	int TIME2 = clock();
#ifdef LOCAL
	cerr << "\n----------------------RUN OVER\n";
	cerr << TIME2 - TIME1 << "ms passed\n";
#endif
	return 0;
}
