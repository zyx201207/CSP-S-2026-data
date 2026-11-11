#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 2e4;
int n, m, sum, cnt[N], x, ans;
char c[N], y;
struct node {
	int cnt;
	char c;
};
vector<node> v;
stack<node> l, rr, t;
queue<node> r;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> cnt[1] >> c[1];
	x = cnt[1], y = c[1];
	sum = x;
	for (int i = 2; i <= n; i++) {
		cin >> cnt[i] >> c[i];
		if (c[i] == y) x += cnt[i];
		else {
			v.push_back({x, y});
			x = cnt[i], y = c[i];
		}
		sum += cnt[i];
	}
	m = ceil(sum * 1.0 / 2);
	v.push_back({x, y});
	x = 0;
	for (int i = 0; i < v.size(); i++) {
		x += v[i].cnt;
		if (x - v[i].cnt < m && x >= m) {
			if (sum % 2 == 1) {
				int num = m - (x - v[i].cnt) - 1;
				if (num != 0) l.push({num, v[i].c});
				num = x - m;
				if (num != 0) r.push({num, v[i].c});
			}
			else {
				int num = m - (x - v[i].cnt);
				if (num != 0) l.push({num, v[i].c});
				num = x - m;
				if (num != 0) r.push({num, v[i].c});
			}
		}
		else if (x < m) l.push(v[i]);
		else if (x > m) r.push(v[i]);
	}
	while (!r.empty()) {
		t.push(r.front());
		r.pop();
	}
	while (!t.empty()) {
		rr.push(t.top());
		t.pop();
	}
	while (!l.empty() || !rr.empty()) {
		node u = l.top(), v = rr.top();
		l.pop(), rr.pop();
		int _ = min(u.cnt, v.cnt);
		if (u.c != v.c) ans += _;
		u.cnt -= _;
		v.cnt -= _;
		if (u.cnt != 0) l.push(u);
		if (v.cnt != 0) rr.push(v);
//		cout << ans << " " << u.c << " " << u.cnt << " " << v.c << " " << v.cnt << "\n";
	}
	cout << ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
