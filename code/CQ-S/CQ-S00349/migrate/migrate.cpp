#include <bits/stdc++.h>
using namespace std;
#define L(i, l, r) for (ll i = (l); i <= (r); i ++)
#define R(i, r, l) for (ll i = (r); i >= (l); i --)
using ll = long long;
namespace Sednorote {
	ll Tid, t;
	ll n, d;
	const ll N = 2e6 + 5;
	ll pos[N], nxt[N], pre[N], c1[N], c2[N], qf1[N], qf2[N], d1[N], d2[N];
	void sol() {
		cin >> n >> d;
		L(i, 1, n) cin >> pos[i];
		if (n < 4) {
			cout << "0\n";
			return;
		}
		L(i, 1, n) d1[i] = d2[i] = 0;
		L(i, 1, n) {
			nxt[i] = upper_bound(pos + 1, pos + n + 1, pos[i] + d) - pos - 1;
			pre[i] = lower_bound(pos + 1, pos + n + 1, pos[i] - d) - pos;
			if (nxt[i] != i) d1[nxt[i]] ++;
			if (pre[i] != i) d2[pre[i]] ++;
		}
//		cout << nxt[n] << "&&&\n";
		ll ans = 0, ac = 0;
		L(i, 1, n) {
			if (pre[i] != i && nxt[pre[i]] == i) c1[i] = c1[pre[i]] + d1[i];
			else c1[i] = d1[i] + 1;
		}
		R(i, n, 1) {
			if (nxt[i] != i && pre[nxt[i]] == i) c2[i] = c2[nxt[i]] + d2[i];
			else c2[i] = d2[i] + 1;
		}
		L(i, 1, n) qf1[i] = qf2[i] = 0;
		L(i, 1, n - 3) {
			if (nxt[i] - i < 2) continue;
			if (pre[nxt[i] - 1] == i && nxt[nxt[i]] != nxt[i] && pre[nxt[nxt[i]]] == nxt[i] - 1) {
				ans += (c1[i] - 1) * (c2[nxt[nxt[i]]] - 1);
			}
			if (pre[nxt[i] - 1] <= i && nxt[nxt[i]] != nxt[i] && pre[nxt[nxt[i]]] == nxt[i] - 1) {
				ans += c2[nxt[nxt[i]]] - 1;
//				cout << c2[5] - 1 << "***\n";
			}
			if (pre[nxt[i] - 1] <= i) {
				qf1[nxt[i] - 1] ++;
			}
//			cout << c1[i] << ' ' << sm[nxt[nxt[i] - 1]] - sm[nxt[nxt[i] - 2]] <<  "&&&\n";
		}
//		cout << nxt[nxt[1]] << "&&&\n";
		R(i, n, 4) {
			if (i - pre[i] < 2) continue;
			if (nxt[pre[i] + 1] >= i && pre[pre[i]] != pre[i] && nxt[pre[pre[i]]] == pre[i] + 1) {
				ans += c1[pre[pre[i]]] - 1;
			}
			if (nxt[pre[i] + 1] >= i) qf2[pre[i]] ++;
		}
		L(i, 1, n - 1) ans += qf1[i] * qf2[i];
		cout << ans << "\n";
	}
	void main() {
		cin >> Tid >> t;
		while (t--) {
			sol();
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Sednorote::main();
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63

0 1
8 9
4 11 12 15 17 25 28 34 
*/
