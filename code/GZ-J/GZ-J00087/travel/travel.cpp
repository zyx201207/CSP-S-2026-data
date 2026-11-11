// ЭѕУћбя GZ-J00087 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ll a1, b1, a2, b2;
	char c1, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	if (a1 == a2) {
		cout << "1";
		if (b1 == b2) {
			cout << "1";
			auto mnmx = minmax(c1, c2);
			c1 = mnmx.first, c2 = mnmx.second;
			if ('A' <= c1 && c2 <= 'C') {
				cout << "1";
				if ((c1 == 'A' && c2 == 'B') || (c1 == 'B' && c2 == 'C'))
					cout << "1\n";
				else
					cout << "0\n";
			} else if (c1 == 'D' && c2 == 'E') {
				cout << "11\n";
			} else {
				cout << "00\n";
			}
		} else {
			cout << "000\n";
		}
	} else {
		cout << "0000\n";
	}
} 
