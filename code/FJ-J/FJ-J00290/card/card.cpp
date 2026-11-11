#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], t[N], ans[N], c[N];
vector<int> g[N];

int main () {
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];	
		g[a[i]].push_back(i);
	}
	for (int i = 1;i <= m;i ++) {
		for (int j = 0;j < g[i].size();j ++) {
			int u = g[i][j];
			if (j + 1 >= g[i].size()) t[u] = -1;
			else t[u] = g[i][j + 1];
		}
	}
	for (int i = 1;i <= n;i ++) {
		if (t[i] == -1) continue;
		int l = i, r = t[i];
		c[l + 1] ++;
		c[r] --;
	}
	t[0] = -1;
	for (int l = 1;l <= n;l ++) {
		int ll = l - 1, rr = t[l - 1];
		if (l > 1 && t[l - 1] != -1) {
			c[ll + 1] --;
			c[rr] ++; 
		}
		vector<int> s(n + 5);
		vector<int> ff(n + 5);
		for (int i = l;i <= n;i ++) {
			s[i] = s[i - 1] + c[i];
			if (s[i] == 0 && !ff[a[i]]) ans[a[i]] ++, ff[a[i]] = 1; 
		}
		//for (int i = 1;i <= n;i ++) cout << s[i] << " ";
	}
	
	for (int i = 1;i <= m;i ++) cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}
