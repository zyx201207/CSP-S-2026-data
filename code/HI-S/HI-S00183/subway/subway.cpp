#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define bep(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
const int maxn = 505, maxm = 1e3 + 5, maxk = 5e5 + 5;
int c, n, m, d, q;
int w[maxm];
int e[maxm][maxm];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) {
		cin >> w[i];
	}
	if(c >= 7 && c <= 11) {//+20pts
		rep(i, 1, n) {
			int k;
			cin >> k;
			rep(j, 1, k) {
				int a, t;
				cin >> a >> t;
				e[i][a] = t;
			}
		}
		rep(i, 1, q) {
			int x, y;
			cin >> x >> y;
			cout << w[x] + e[x][x] + e[x][y] + w[y];
		}
		return 0;
	}
	else {
		cout << "CSP-S RP++!\n";
	}
	return 0;
}
