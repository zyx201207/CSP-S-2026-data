#include<bits/stdc++.h>

#define FOR(i, j, k) for(ll i = j;i <= k;++i)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const ll N = 5e5 + 10;
ll m, n, a[N], ans = 1, need;
queue<ll> q;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	FOR(i, 1, n) {
		while(!q.empty() && need + q.size() * (a[i] - a[i - 1]) > m) {
			need -= (a[i - 1] - q.front());
			q.pop();
		}
		need += q.size() * (a[i] - a[i - 1]);
		q.push(a[i]);
		ans = max(ans, (ll)q.size());
	}
	cout << ans;
	return 0;
}
/*
Why I need to add 1
It's tooooooooooooo not elegant
let me try a handmake one
15:32 AC Completely
The fastest time!
*/
