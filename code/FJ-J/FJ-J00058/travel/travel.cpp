#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void solve() {
	string a, b, c, d; cin >> a >> b >> c >> d;
	if(a != c) {
		cout << "0000" << endl;
	} else {
		string p = b.substr(0, 2), q = d.substr(0, 2);
		if(p != q) {
			cout << "1000" << endl;
		} else {
			char s = b[2], t = d[2];
			if(s <= 'C' && t > 'C' || s > 'C' && t <= 'C') {
				cout << "1100" << endl;
			} else {
				if(abs(s - t) != 1) {
					cout << "1110" << endl;
				} else {
					cout << "1111" << endl;
				}
			}
		}
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int T = 1;
//	cin >> T;
	while(T--) solve();
	
	return 0;
}
