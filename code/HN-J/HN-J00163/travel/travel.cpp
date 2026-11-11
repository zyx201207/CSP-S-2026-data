#include<bits/stdc++.h>
#define ll long long
#define inf 1e9
using namespace std;
int a, b;
string x, y;
void solve() {
	cin >> a >> x >> b >> y;
	if (a != b) {
		cout << "0000";
	} else if (x[0] != y[0] || x[1] != y[1]) {
		cout << "1000";
	} else if (!((x[2] >= 'A' && x[2] <= 'C' && y[2] >= 'A' && y[2] <= 'C') || (x[2] >= 'D' && x[2] <= 'F' && y[2] >= 'D' && y[2] <= 'F'))) {
		cout << "1100";
	} else if (x[2] != y[2] - 1 && x[2] != y[2] + 1) {
		cout << "1110";
	} else {
		cout << "1111";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}

