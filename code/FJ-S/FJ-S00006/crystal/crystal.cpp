#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

const int N = 5e5+7, M = 2e5+7;

ll n, m;
ll a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	// NO LONG LONG NO ACCPTED
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) s[i] = a[i] + s[i-1];
	
	ll l = 1, r = 1;
	ll ans = 0;
	while (l <= r && r <= n) {
		if (s[r] - s[l-1] - (r-l+1)*a[r] + m < 0) {
			l++;
		}
		else {
			ans = max(ans, (r-l+1));
			r++;
		}
	}
	cout << ans << '\n';
	return 0;
}
