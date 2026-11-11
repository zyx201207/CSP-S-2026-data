#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 1e5 + 10;

int main() {
  	freopen("travel.in", "r", stdin);
  	freopen("travel.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b;
	string n, m;
	cin >> a >> n >> b >> m;
	if (a == b) {
		cout << 1;
		if (n[0] == m[0] && n[1] == m[1]) {
			cout << 1;
			int f1 = 0, f2 = 0;
			if (n[2] == 'A' || n[2] == 'B' || n[2] == 'C') f1 = 1;
			else f1 = 2;
			if (m[2] == 'A' || m[2] == 'B' || m[2] == 'C') f2 = 1;
			else f2 = 2;
			if (f1 == f2) {
				cout << 1;
				if (abs(n[2] - m[2]) == 1) cout << 1;
				else cout << 0;
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}

