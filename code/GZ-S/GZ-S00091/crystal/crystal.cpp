// GZ-S00091 »Æ¼ÑÂå »ªÊ¦Ò»¹óÑô 
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, r, l) for (int i = r; i >= l; i--)
#define iv inline void
#define it inline int

using namespace std;

const int N = 5e5 + 10;

int n, m;
int w[N], s[N];

signed main() {
	 freopen("crystal.in", "r", stdin);
	 freopen("crystal.out", "w", stdout);	
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m; upp(i, 1, n) cin >> w[i]; 
	sort(w + 1, w + n + 1);
	upp(i, 1, n) s[i] = s[i - 1] + w[i];
	int ans = 1;
	upp(i, 2, n) {
		int rr = i;
		int l = 1, r = i - 1, res = i;
//		dww(j, i - 1, 1) if ((i - j) * w[i] - s[i - 1] + s[j] <= m) res = j; 
		while (l <= r) {
			int mid = l + r >> 1ll;
			if ((i - mid) * w[i] - s[i - 1] + s[mid - 1] <= m) res = mid, r = mid - 1;
			else l = mid + 1;
		}
//		cout << s[i] - s[res - 1] << endl;
		ans = max(ans, i - res + 1);
//		cout << res << ' ' << i << ' ' << s[i] << ' ' << d[i] << endl; 
	}
	cout << ans << endl;
	return 0;
}
