#include <bits/stdc++.h> 
using namespace std;
int n, m, a[300002], ans[300002], pos;
bool flag[300002];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			flag[j] = false;
		pos = i;
		for (int j = i; j <= n; j++){
			if (!flag[a[j]]) flag[a[j]] = true;
			else pos = j;
		}
		for (int j = pos; j <= n; j++)
			ans[a[j]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
	
}
