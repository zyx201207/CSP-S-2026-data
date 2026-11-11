#include <bits/stdc++.h>
using namespace std;

int n, m, lasti[500100], a[500100], cnt[500100], ans[500100], flag = 1;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {cin >> a[i]; cnt[a[i]] ++;}
	for(int i = 1; i <= n; i ++) lasti[a[i]] = i;
	if(m == 1) {cout << n; return 0;}
	if(m == 2) {
		if(a[n] == 1){cout << n << " " << cnt[2]; return 0;}
		else {cout << cnt[1] << " " << n; return 0;}
	}
	for(int i = 1; i <= n - 1; i ++)
		if(a[i] > a[i + 1]) flag = 0;
	if(flag == 1) {
		for(int i = 1; i <= m; i ++) cout << lasti[i] << " ";
		return 0;
	}
}
