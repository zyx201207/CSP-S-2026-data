//Òª¼ÇµÃÐ´ 
//freopen(" .in", "r", stdin);
//freopen(" .out", "w", stdout);

#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], f[300005], ans[300005];
stack <int> stk; 

int main() {
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	for (int k=1;k<=n;k++) {
		memset(f, 0, sizeof f);
		for (int i=k;i<=n;i++) {
			if (f[a[i]]) {
				while (stk.top() != a[i]) {
					f[stk.top()] = 0;
					stk.pop();
				}
			}
			else {
				stk.push(a[i]);
				f[a[i]] = 1;
			}
		}
		while (stk.size()) {
			ans[stk.top()] ++;
			stk.pop();
		}
	}
	for (int i=1;i<=m;i++) cout << ans[i] << ' ';
	
	return 0;
}
