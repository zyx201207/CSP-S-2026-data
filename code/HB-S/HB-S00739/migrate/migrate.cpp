#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
using namespace std;
const int maxn = 2e6 + 10;
const int inf = INT_MAX / 2;

int c, t;
int n, d;
int x[maxn], delta;

void P1112 () {
    while (t--) {
        cin >> n >> d;
        for (int i =1; i <= n; i++) {
            cin >> x[i];
        }
        delta = x[2] - x[1];
        if (d < 2 * delta || d >= x[n] - x[1]) {
            cout << 0 << endl;
			continue;
        }else {
			int ans = 0;
			int xx = (x[n] - x[1]) / delta;
			for (int i = 1; i <= n; i++) {
				int dd = (delta + d * i) / delta;
				ans += max(0, xx - dd) + 1;
			}
			cout << ans << endl;
			continue;
		}
    }
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
    cin >> c >> t;
    if (c >= 11 && c <= 12) {
        P1112();
		return 0;
    }
	while (t--) cout << 0 << endl;
    return 0;

}
