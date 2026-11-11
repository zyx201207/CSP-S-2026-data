#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q;
int w[5000010],a[5000010][5000010], t[5000010][5000010];
int k[5000010];
int x, y;
int jd[5000010][5000010] = {999999999};
int zb[5000010][5000010];

void find () {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int o = 1; o <= k[i]; o++) {
				for (int p = 1; p <= k[j]; p++) {
					if(a[i][o] == a[j][p]) {
						if(t[i][o] + t[j][p] < t[i][zb[i][j]] + t[j][zb[i][j]] || zb[i][j] == 0) {
							zb[i][j] = a[i][o];
						}
						jd[i][j] = min(jd[i][j], t[i][o] + t[j][p]);
					}
				}
			}
		}
	}
}

long long solve() {
	long long ans = 0;
	ans += w[x];
	bool check = 0;
	int tx = 0;
	int xl = 0, yl = 0;
	int jdn = 999999999;
	ans += w[y];
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= k[i]; j++) {
			for (long long l = j + 1; l <= k[i]; l++) {
				if(a[i][j] == x && (jd[xl][yl] < jdn || jdn == 999999999)) {
					xl = i;
				}
				if(a[i][j] == y && (jd[xl][yl] < jdn || jdn == 999999999)){
					yl = i;
				}
				if(a[i][j] == x && a[i][l] == y){
					ans += t[i][x];
					ans += t[i][y];
					check = 1;
				} 
			}
		}
	}
	if(check == 1) {
		return ans;	
	} else {
		ans += t[xl][x];
		ans += t[yl][y];
		ans += t[xl][zb[xl][yl]];
		ans += t[yl][zb[xl][yl]];
		return ans + 4;
	}
	
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	find();
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		cout << solve() << endl;
	}
	return 0;
}
