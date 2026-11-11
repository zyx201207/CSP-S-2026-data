# include <bits/stdc++.h>
using namespace std;

int ans, n, m, a[200005];
int aa[200005][32], res[32];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++){
		int j = 0;
		while (a[i]){
			aa[i][j++] = a[i] % 2;
			a[i] = a[i] / 2;
		}
	}
	if (m == 1){
		for (int i = 0; i < n; i++) ans = max(ans, a[i]);
	}
	else if (m == 2){
		for (int i = 0; i < n; i++){
			for (int j = i; j < n; j++){
				for (int k = 0; k < 32; k++){
					res[k] = aa[i][k] && aa[j][k];
				}
			}
		}
	}
	else if (m == n){
		for (int i = 0; i < 32; i++){
			int an = 1;
			for (int j = 0; j < n; j++){
				an = an && aa[j][i];
			}
			res[i] = an;
		}
	}
	for (int i = 0; i < 32; i++) ans += res[i] * pow(2, i);
	cout << ans;
	return 0;
}
