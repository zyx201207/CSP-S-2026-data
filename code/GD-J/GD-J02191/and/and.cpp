#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans = 0;
int a[200005];
void dfs(int pos,int cnt,int sum) {
	if (cnt > m) return ;
	if (pos == n + 1) {
		if (cnt == m) ans = max(ans,sum);
		return ;
	}
	dfs(pos + 1,cnt,sum);
	dfs(pos + 1,cnt + 1,(pos > 1 ? sum & a[pos] : a[pos]));
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(1,0,0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
