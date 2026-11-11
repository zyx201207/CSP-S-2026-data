#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m, ans;
int q, a[N], box[N];
bool vis[N];

void dfs (int x) {
	if (x == m + 1) {
		int tmp = box[1];
		for (int i = 2;i <= m;++i) tmp = tmp & box[i];
		ans = max(ans, tmp);
	}
	for (int i = 1;i <= n;++i) {
		if (!vis[i]) {
			box[x] = a[i];
			vis[i] = true;
			dfs(x + 1);
			vis[i] = false;
		}
	}
	return ;
}

void solve () {
	sort (a + 1, a + n + 1);
	
	ans = a[n];
	q = n - 1;
	--m;
	
	while (m--) {
		ans &= a[q];
		--q;
	}
}

int main () {
	
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);

	scanf ("%d%d", &n, &m);
	for (int i = 1;i <= n;++i) scanf ("%d", &a[i]);
	
	if (n <= 20) dfs(1);
	else if (n <= 2000){
		if (m == 1)
			for (int i = 1;i <= n;++i)
				ans = max(ans, a[i]);
		if (m == n) {
			ans = a[1];
			for (int i = 2;i <= n;++i)
				ans &= a[i];
		}
		if (m == 2) {
			for (int i = 1;i <= n;++i)
				for (int j = i + 1;j <= n;++j)
					ans = max(ans, a[i] & a[j]);
		}
	} else solve();
	
	printf ("%d\n", ans);
	
	return 0;
}
