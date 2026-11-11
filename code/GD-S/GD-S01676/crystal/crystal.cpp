#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 3e6+10;
LL a[N], s[N];
LL n, m;

bool check(LL l, LL r) {
	LL up = (r-l+1) * a[r];
	LL down = s[r] - s[l-1];
	return ((up - down) <= m);
}

void solve() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) {
		s[i] = s[i-1] + a[i];
	}
	LL ans = 0;
	for(int i=1; i<=n; i++) {
		LL l=1, r=i;
		while(l < r) {
			LL mid = l+((r-l)>>1);
			if(check(mid, i)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i-l+1);
	}
	cout << ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) {
		solve();
	}
	
	return 0;
} 
