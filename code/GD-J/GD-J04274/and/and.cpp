#include <bits/stdc++.h>

#define FOR(i, j, k) for(ll i = j;i <= k;++i)
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const ll N = 2e5 + 10;
ll m, n, a[N], ans;

void dfs(ll now, ll cnt, ll ret) {
	if(cnt == m) {
		ans = max(ans, ret);
		return;
	}
	if(now > n || (!ret)) return;
	dfs(now + 1, cnt, ret);
	dfs(now + 1, cnt + 1, ret & a[now]);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >>  m;
	FOR(i, 1, n) cin >> a[i];
	if(n <= 20) {
		dfs(1, 0, (1ll << 31) - 1);
		cout << ans;
	} else if(m == 1) {
		sort(a + 1, a + n + 1, greater<ll>());
		cout << a[1];
	} else if(m == 2) {
		FOR(i, 1, n) FOR(j, i + 1, n) ans = max(ans, a[i] & a[j]);
		cout << ans;
	} else if(m == n) {
		ans = a[1];
		FOR(i, 2, n) ans &= a[i];
		cout << ans;
	} else {
		sort(a + 1, a + n + 1, greater<ll>());
		ll idx = 1;
		while(__builtin_popcountll(a[idx]) == 1) ++idx;
		ans = a[idx];
		for(ll i = idx + 1;i - idx <= m - 1;++i) ans &= a[i];
		cout << ans;
	}
	return 0;
}
/*
Sort it and select the max m?
seems not too wrong
hacked by 512&511 = 0
so only do not do that when the top is 2^k
A little bit nice but It is too: code for sampling
uhhh
Just nobody can believe what I'm doing!
What
I 've passed All the test cases?
It seems to be hacked by:

24 5 3
good: 5 & 3 = 1
bad: 24 & 5 = 0
50pts for sure now
*/
