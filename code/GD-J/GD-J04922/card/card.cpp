#include <bits/stdc++.h>
using namespace std;
int a[500010];
int ans[300010];
int nxt[300010];
int ms[300010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	bool f = 1;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		nxt[a[i]] = i;
		if (a[i] < a[i - 1]){
			f = 0;
		}
		ms[a[i]] ++;
	}
	if (f){
		int x = 0;
		for (int i = 1; i <= m; i ++){
			cout << x + ms[i] << " ";
			x += ms[i];
		}
		return 0;
	}
	for (int i = 1; i <= n; i ++){
		for (int j = i; j <= n; j ++){
			ans[a[j]] ++;
			j = nxt[a[j]];
		}
	}
	for (int i = 1; i <= m; i ++){
		cout << ans[i] << " ";
	}
	return 0;
}
