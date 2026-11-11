#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;

int n, a[N];
ll s[N], b[N];
char c[N];

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i] >> c[i], s[i] = s[i - 1] + a[i];
	for (int i = n; i >= 1; i --) b[i] = b[i + 1] + a[i];
	ll ans = 0;
	if (c[1] != c[n]) ans += min(a[1], a[n]);
	for (int i = 1, j = n; s[i] + b[j] <= s[n]; ) {
//		cout << i << " " << j << "\n";
		if (s[i] <= b[j]) while (s[i] <= b[j]) i ++;
		else while (s[i] > b[j]) j --;
		if (c[i] != c[j]) ans += min(s[i], b[j]) - max(s[i] - a[i] + 1, b[j] - a[j] + 1) + 1;
	}
	
	cout << ans << "\n";
	
	return 0;
}

