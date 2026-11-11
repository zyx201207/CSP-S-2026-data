#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010], ans[300010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ans[a[i]]++;
	}
	for(int i = 2; i <= m; i++){
		ans[i] += ans[i - 1];
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}

