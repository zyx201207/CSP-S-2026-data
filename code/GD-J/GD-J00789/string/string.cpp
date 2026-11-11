#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, sum, tmp;
struct range{
	ll l;
	char a;
}r[200005];
queue<range> q1, q2;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i].l >> r[i].a;
		sum += r[i].l;
	}
	sum /= 2;
	for (int i = 1; i <= n; i++) {
		if (sum - tmp <= r[i].l) {
			q1.push({sum - tmp, r[i].a});
			break;
		} else {
			q1.push(r[i]);
			tmp += r[i].l;
		}
	}
	tmp = 0;
	for (int i = n; i >= 1; i--) {
		if (sum - tmp <= r[i].l) {
			q2.push({sum - tmp, r[i].a});
			break;
		} else {
			q2.push(r[i]);
			tmp += r[i].l;
		}
	}
	tmp = 0;
	while (!q1.empty()) {
		range u = q1.front(), v = q2.front();
		if (u.l == v.l) {
			q1.pop();
			q2.pop();
			if (u.a != v.a) {
				tmp += u.l;
			}
		} else if (u.l < v.l) {
			q1.pop();
			q2.front().l -= u.l;
			if (u.a != v.a) {
				tmp += u.l;
			}
		} else {
			q2.pop();
			q1.front().l -= v.l;
			if (u.a != v.a) {
				tmp += v.l;
			}
		}
	}
	cout << tmp;
	return 0;
}
