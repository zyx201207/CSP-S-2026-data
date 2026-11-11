# include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], gm[500005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int ans[m+1];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) ans[i] = 0;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			for (int k = i; k < j; k++){
				if (gm[k] == a[j]){
					for (int l = k; l < j; ++l) gm[l] = 0;
					break;
				}
			}
			gm[j] = a[j];
		}
		for (int j = i; j < n; j++){
			ans[gm[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
