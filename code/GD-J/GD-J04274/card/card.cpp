#include <bits/stdc++.h>

#define FOR(i, j, k) for(ll i = j;i <= k;++i)
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const ll N = 5e5 + 10;
ll m, n, a[N], ans[N], sum[N];
vector<ll> nxt[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i];
		nxt[a[i]].emplace_back(i);
		if(n > 5000) sum[i] = i;
	}
	if(n <= 5000) {
		FOR(i, 1, n) {
			ll j = i;
			FOR(k, i, n) ++ans[a[k]];
			while(j <= n) {
				ll l = j, r = upper_bound(nxt[a[l]].begin(), nxt[a[l]].end(), j) - nxt[a[l]].begin();
				if(r >= nxt[a[l]].size()) ++j;
				else {
					for(ll k = l;k < nxt[a[l]][r];++k) --ans[a[k]];
					j = nxt[a[l]][r];
				}
			}
		}
		ans[a[n]] = n;
	} else {
		FOR(i, 1, n) sum[i] = 1;
		FOR(i, 1, n) {
			ll l = i, r = upper_bound(nxt[a[i]].begin(), nxt[a[i]].end(), i) - nxt[a[i]].begin();
			if(r >= nxt[a[i]].size()) continue;
			else {
				ll len = nxt[a[i]][r] - l;
				sum[l] -= len, sum[nxt[a[i]][r]] += len;
			}
		}
		FOR(i, 1, n) sum[i] = sum[i - 1] + sum[i];
	}
	FOR(i, 1, m) cout << ans[i] << ' ';
	return 0;
}
/*
Let's consider a card's contribution one by one
*/
