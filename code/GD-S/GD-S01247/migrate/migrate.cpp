#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
const int N = 5e3 + 5;
int n, a[N], m, c, b[N], d[N];
bool vis[N];
void bfs(int x){
	queue<int> q, t;
	q.push(x);
	t.push(1);
	while (!q.empty()){
		int u = q.front(), v = t.front();
		b[u]++;
		q.pop();
		t.pop();
		if (vis[u]) continue;
		d[u] = v;
		vis[u] = 1;
		for (int i = 1; i <= n; i++){
			if (abs(a[i] - a[u]) <= m && d[i] >= v + 1){
				d[i] = v + 1;
				t.push(v + 1);
				q.push(i);
			}
		}
	}
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int ttt;
	scanf("%lld%lld", &c, &ttt);
	while (ttt--){
		scanf("%lld%lld", &n, &m);
		for (int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		if (c <= 10){
			set<pair<int, int> > s;
			for (int i = 1; i <= n; i++){
				memset(b, -1, sizeof b);
				memset(d, 0x3f, sizeof d);
				memset(vis, 0, sizeof vis);
				bfs(i);
				for (int j = 1; j <= n; j++){
					if (i != j && b[j] == 1){
						int a = i, b = j;
						if (a > b) swap(a, b);
						s.insert({a, b});
					}
				}
			}
			printf("%lld\n", s.size());
			continue;
		}
			int t = 0, ans = 0;
			for (int i = 1; i <= n; i++){
				if (a[i] - a[1] <= m && a[n] - a[i] <= m) t = i;
			}
			for (int i = 1; i <= n; i++){
				int l = lower_bound(a + 1, a + 1 + n, a[i] - m) - a - 1;
				int r = upper_bound(a + 1, a + 1 + n, a[i] + m) - a;
				ans += l + (n - r + 1);
			}
			printf("%lld\n", ans / 2);
	}
	return 0;
}
