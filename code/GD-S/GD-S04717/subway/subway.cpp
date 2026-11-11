#include <bits/stdc++.h>
using namespace std;
int a[505], t[505][50005], zdxl[505], qdxl[505], x[50005], x1[505][50005];
bool b[505][50005];
int main (){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> x[i];
		for (int j = 1; j <= x[i]; j++){
			cin >> x1[i][j];
			b[i][x1[i][j]] = true;
			cin >> t[i][x1[i][j]];
		}
	}
	while (q--){
		int l, r;
		cin >> l >> r;
		int ans = a[l];
		if (l == r){
			cout << ans << endl;
			continue;
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++){
			if (b[i][r]){
				cnt1++;
				zdxl[cnt1] = i;
			}
		}
		for (int i = 1; i <= n; i++){
			if (b[i][l]){
				cnt2++;
				qdxl[cnt2] = i;
			}
		}
		int cs = 1, ans1 = a[l], ans2 = a[l], ans3 = a[l];
		for (int i = 1; i <= cnt1; i++){
			for (int j = 1; j <= cnt2; j++){
				if (zdxl[i] == qdxl[j]){
					if (cs == 1){
						ans1 += t[i][l] + t[i][r] + a[r];
						cs++;
					}else {
						ans2 += t[i][l] + t[i][r] + a[r];
						ans1 = max(ans1, ans2);
						ans2 = ans3;
					}
				}
			}
		}
		if (ans1 != ans){
			cout << ans1 << endl;
			continue;
		}
		int ansx = 0, xr = zdxl[cnt1], xl = qdxl[cnt2];
		for (int i = 1; i <= x[xl]; i++){
			for (int j = 1; j <= n; j++){
				if (b[j][x1[j][i]]){
					if (j == xr){
						ansx = ans3;
						ansx += t[xl][l] + t[xl][x1[j][i]] + t[xr][x1[j][i]]+ t[xr][r] + a[r];
						ans = max(ans, ansx);
					}
				}
			}
		}
		cout << ans << endl;
	}
}
