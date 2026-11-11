#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, p, w[100005], k[100005], a[2005][2005], t[2005][2005], x[100005], y[100005], asn;
void dfs (int d, int l, int j, int dj) {
}
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int qq[100005];
	for (int j = 1; j <= n; j++) {	
		cin >> qq[j];
		for (int i = 1; i <= 2 * qq[i]; i++) {
			cin >> a[j][i] >> t[j][i];
		}
	}
	for (int i = 1; i <= p; i++) {
		cin >> x[i] >> y[i];
		asn = 0;
		asn += w[x[i]];
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= qq[i]; k++) {
				asn += t[j][k];
			}
		}
		asn += w[y[i]];
		cout << asn << endl; 
	}
	return 0;
}
