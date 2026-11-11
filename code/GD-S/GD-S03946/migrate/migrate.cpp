#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;

#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

const int N = 2e6 + 5;
int c, t, n; ll d, x[N], pre[N];

void solve() {
	cin >> n >> d;
	for(int i = 1, ptr = 1; i <= n; i++) {
		cin >> x[i];
		while(ptr < i && x[ptr] < x[i] - d) ptr++;
		pre[i] = ptr;
	} pre[n + 1] = pre[n + 2] = n;
	ll res = 0;
	for(int i = n; i; i--) {
//		cout << "i = " << i << endl;
		int a = i, b = i + 1, c = i + 1, d = i + 1; ll tmp = 0;
//		cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
		while(1) {
			int _a, _b, _c, _d;
			_a = pre[a], _d = a;
			if(_a < 1) break;
			if(a == b) {
				if(b == c) _b = _c = pre[a];
				else _b = pre[a], _c = pre[b + 1];
			} else if(a + 1 == b) _b = _c = pre[b];
			else _b = pre[a + 1], _c = pre[a + 2];
			d = _d, c = min(_c, d), b = min(_b, c), a = min(_a, b);
			res += c - b, tmp += c - b;
//			cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
			if(a == d) break;
		}
//		cout << "res: " << i << ' ' << tmp << endl;
		pre[i] = i - 1;
	} cout << res << '\n';
}

int main() {
	file(migrate);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) solve();
	cout << flush;
	return 0;
}
/*
0 5
4 2
1 2 3 4
5 2
1 2 3 4 5
6 3
0 1 2 3 4 7
8 3
0 1 2 4 8 10 11 13
1 3
0
*/
