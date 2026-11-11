#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mkp make_pair
#define fi first
#define se second

const int N = 5e5 + 5, mod = 1e9 + 7; 

ll n, m;
ll a[N], s[N];

void slv() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i - 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (a[i] * (i - 1 - mid + 1) - (s[i - 1] - s[mid - 1]) <= m)
				r = mid;
			else
				l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans << '\n';
}

int main() {
//	freopen("crystal4.in", "r", stdin);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--)
		slv();
	return 0;
}
