//GZ-J00625 罗思妤 北京师范大学贵阳附属中学 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, m, cnt, mm;
ll t, k, ans;
vector <ll> a[31];
void dfs (ll ma) {
	if (a[ma].size () == m) {
		ans = a[ma][0];
		for (int i = 1; i < m; i++) ans &= a[ma][i];
		return ;
	}
	for (int i = ma - 1; i >= 0; i--) {
		if (a[i].size () < m) continue;
		a[i].clear ();
		for (int j = 0; j < a[ma].size(); j++) {
			k = a[ma][j], k >>= i;
			if (k & 1) a[i].push_back(a[ma][j]);
		}
		if (a[i].size () >= m) dfs (i);
	}
	ans = a[ma][0];
	for (int i = 1; i < m; i++) ans &= a[ma][i];
	return ;
}
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &t);
		k = t, cnt = -1;
		while (k) {
			cnt++;
			if (k & 1) {
				a[cnt].push_back(t);
				if (a[cnt].size () >= m) mm = max (mm, cnt);
			}
			k >>= 1;
		}
	}
	dfs (mm);
	printf ("%lld", ans);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
