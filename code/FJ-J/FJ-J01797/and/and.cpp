#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
	int x, y, id;
}a[200005];
int n, m, ans;
bool cmp(node a, node b) {
	if (a.y != b.y) return a.y > b.y;
	else return a.id < b.id;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		a[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x;
		int t = a[i].x;
		while(t) {
			if (t ^ 1 == 1) {
				a[i].y++;
			}
			t >>= 1;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1].x;
	for (int i = 2; i <= m; i++) {
		ans &= a[i].x;
	}
	cout << ans;
	return 0;
}
