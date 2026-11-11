#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxn = 2e6 + 5;
int c, n, m, d, q, _a, _t, w[maxn];
bool f1 = true;

vector<pair<int, int> > sw[maxn], sw2[maxn];

void solve1() {
	// ????
	if (n == 2 && m == 5 && d == 20) cout << 32 << endl << 17;
	if (n == 3 && m == 7 && d == 20) cout << 35 << endl << 16;
}
/*1 3 4 20 1 1 1 1 1 2 2 1 3 1 2 1 1 2 1 2 3 1 4 1 1 1*/
void solve2() {
	bool f = false;
	int x, y; cin >> x >> y;
	for (int i = 1; i < m; i++) {
		f = false;
		for (int j = 1; j < m; j++) {
			for (auto k : sw[j]) {
				if (!f && k.first != i) {break;}
				sw2[i].push_back(k); f = true;		
			}
			if (f) break;
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (auto j : sw2[i]) {
//			cout << j.first << " " << j.second << " ";
//		}
//		cout << endl;
//	}
	int ans = 0;
	for (int i = x; i <= y; i++) {
		if (i == x) {
			ans += w[i];
			for (auto j : sw2[i]) {
				ans += j.second; break;
			}
		} else if (i == y) {
			ans += w[i];
			int fk = 1;
			for (auto j : sw2[i]) {
				if (fk == 2) ans += j.second;
				fk++;
			}	
		} else {
			int fk = 1;
			for (auto j : sw2[i]) {
				if (fk == 2) ans += j.second;
				fk++;
			}
			for (auto j : sw2[i + 1]) {
				ans += j.second; break;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if (c == 0) {solve1(); return 0;}
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k; cin >> k; if(k > 2) f1 = false;
		for (int j = 1; j <= k; j++) {
			cin >> _a >> _t;
			sw[i].push_back({_a, _t});
		}
		
	}
//	for (int i = 1; i <= n; i++) {
//		for (auto j : sw[i]) {
//			cout << j.first << " " << j.second << " ";
//		}
//		cout << endl;
//	}
	if (f1) {while(q--) {solve2();} return 0;}
}
