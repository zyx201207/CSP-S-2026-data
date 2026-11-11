#include <bits/stdc++.h>
using namespace std;
int n, m, a[600005], t[600005], ans[600005], o[600005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		memset(t, 0, sizeof(t));
		memset(o, 0, sizeof(o));
		for (int j = i; j <= n; j++){
			t[a[j]]++;
			if (t[a[j]] == 2){
				for (int k = j - 1; ; k--){
					if (o[k]) continue;
					t[a[k]]--;
					o[k] = 1;
					if (a[k] == a[j]) break;
				}
			}
		}
		for (int j = 1; j <= m; j++){
			ans[j] += t[j];
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
