#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel2.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int na, nb;
	string sita, sitb;
	cin >> na >> sita >> nb >> sitb;
	if (na == nb) {
		cout << 1;
		if (sita.substr(0, 2) == sitb.substr(0, 2)) {
			cout << 1;
			if (sita[2] <= 'C' && sitb[2] <= 'C') {
				cout << 1;
				if (abs(sita[2] - sitb[2]) == 1) cout << 1;
				else cout << 0;
			} else if (sita[2] >= 'D' && sitb[2] >= 'D') cout << 11;
			else cout << "00";
		} else cout << "000";
	} else cout << "0000";
}

