#include <bits/stdc++.h>

#define FOR(i, j, k) for(ll i = j;i <= k;++i)
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const ll N = 2e5 + 10;
ll l, n, r, ans, sum;
pair<ll, char> a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i].first >> a[i].second;
		sum += a[i].first;
	}
	l = 1, r = n;
	while(l <= r) {
		if(a[r].first >= a[l].first) {
			if(a[r].second != a[l].second) ans += a[l].first;
			a[r].first -= a[l].first;
			++l;
		} else {
			if(a[r].second != a[l].second) ans += a[r].first;
			a[l].first -= a[r].first;
			--r;
		}
	}
	cout << ans;
	return 0;
}
/*
OK Still solvable
It seems harder than seat or even some S T1 in simulation
2e14 >> 1e8 --> unAC
09:29 AC
*/