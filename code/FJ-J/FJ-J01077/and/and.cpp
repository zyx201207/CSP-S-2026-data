#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5, LOG = 31;
int POW[LOG];
int n, m;
bool num[MAXN][LOG];
bool ans[LOG];
bool can[MAXN];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	memset(can, true, sizeof can);
	POW[0] = 1;
	for(int i = 1; i < LOG; i++) {
		POW[i] = POW[i - 1] << 1;
	}
	cin >> n >> m;
	for(int i = 0, x; i < n; i++) {
		cin >> x;
		for(int j = LOG - 1; j >= 0; j--) {
			if(POW[j] <= x) {
				num[i][j] = 1;
				x -= POW[j];
			}
		}
	}
	for(int i = LOG - 1; i >= 0; i--) {
		int cnt = 0;
		for(int j = 0; j < n; j++) {
			if(!can[j]) continue;
			if(num[j][i] == 1) cnt++;
		}
		if(cnt >= m) {
			for(int j = 0; j < n; j++) {
				if(num[j][i] == 0) {
					can[j] = false;
				}
			}
			ans[i] = 1;
		} else {
			ans[i] = 0;
		}
	}
	int Ans = 0;
	for(int i = 0; i < LOG; i++) {
		Ans += POW[i] * ans[i];
	}
	cout << Ans << endl;
	return 0;
}
// 手搓小样例都对，复杂度也对，为啥大样例不输出？ 
