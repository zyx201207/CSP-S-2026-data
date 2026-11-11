#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, stk[500500], top, a[500500], ans[300300], id[300300];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = n; i >= 1; i--) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(id[a[i]] == 0) {
			stk[++top] = a[i];
			id[a[i]] = top;
			for(int j = 1; j <= top; j++) cout << stk[j] << ' ';
		}
		else {
			while(top > id[a[i]]) {
				id[stk[top]] = 0;
				--top;
			}
			for(int j = 1; j <= top; j++) cout << stk[j] << ' ';
		}
		for(int j = 1; j <= top; j++) ans[stk[j]]++;
		cout << '\n';
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
