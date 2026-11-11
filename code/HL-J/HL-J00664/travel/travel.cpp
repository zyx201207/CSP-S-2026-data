#include<bits/stdc++.h>

using namespace std;

long long a, b, c, d;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string x1, x2, s1, s2;
	cin >> x1 >> x2 >> s1 >> s2;
	if(x1 == s1) {
		a = 1;
		if(x2[0] == s2[0] && x2[1] == s2[1]) {
			b = 1;
			if((x2[2] <= 'C' && s2[2] <= 'C') || (x2[2] >= 'D' && s2[2] <= 'D')) {
				c = 1;
				if(abs(x2[2] - s2[2]) == 1) d = 1;
				cout << a << b << c << d << endl;
			} else cout << a << b << c << d << endl;
		} else cout << a << b << c << d << endl;
	} else cout << a << b << c << d << endl;
	return 0;
}
