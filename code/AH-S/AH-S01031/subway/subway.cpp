/*CN*/
#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, w[N], x, y, ans, f[N];
struct line{
	int k;
	vector<int> v, t;
}a[N];//第i条线路经过a[i].k个站台， 分别为a[i].v[j]
struct cz{
	int cnt = 0;
	vector<int> l, t;
}b[N];//第i个站台经过b[i].cnt个线路， 分别为b[i].l[j]
void search(int cur, int step) {//目前所在第cur个站台
	if (cur == y) {
		ans = min(ans, step);
		return;
	}
	for (int i = 0; i < b[cur].cnt; i++) {
		int to_xl = b[cur].l[i], tim1 = b[cur].t[i];
		//枚举第to_xl条线路
		for (int j = 1; j <= a[to_xl].k; j++) {
			int to = a[to_xl].v[j], tim2 = a[to_xl].t[j];
			if (f[to] == 0) {
				f[to] = 1;
				search(to, step + tim2 + tim1);
				f[to] = 0;
			}
		}
	}
}
int main() { 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].k;//line i has a[i].k platforms
		for (int j = 1, vv, tt; j <= a[i].k; j++) {
			cin >> vv >> tt;
			a[i].v.push_back(vv);
			a[i].t.push_back(tt);
			//platform a[i].v[j - 1] needs a[i].t[j - 1] time
			b[vv].cnt++;
			b[vv].l.push_back(i);
			b[vv].t.push_back(a[i].t[j - 1]);
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		ans = INT_MAX;
		search(x, 0);
		cout << ans + w[x] + w[y]<< "\n";
	}
	return 0;
}
