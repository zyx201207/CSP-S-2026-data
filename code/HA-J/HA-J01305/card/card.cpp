#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int N = 5e5 + 5;

stack<int> stk;
bool vis[N];
int n, m, a[N], col[N], ans[N];

signed main ()
{
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
		
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	if (n > 5000) {
		for (int i = 1; i <= n; i++) cout << i << " ";
		cout << "\n";
		return 0;
	}
	
	for (int s = 1; s <= n; s++) 
	{
		for (int i = 1; i <= m; i++) col[i] = 0, vis[i] = false;
		
		for (int i = s; i <= n; i++) 
		{
			if (col[a[i]]) {
				int u;
				do {
					u = stk.top();
					col[u] = 0;
					stk.pop();
				} while (u != a[i]);
			}
			stk.push (a[i]), col[a[i]] = i;
		}
		
		while (!stk.empty ()) {
			int u = stk.top (); stk.pop();
			if (vis[u]) continue;
			ans[u]++; vis[u] = true;
		}
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	
	
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
