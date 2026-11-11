#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI ;
using namespace std;
long long n, m, k, x, y, a[1234];
string s, t, ss, tt;
char xx, yy;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	a[(int)'A'] = 1, a[(int)'B'] = 3, a[(int)'C'] = 5, a[(int)'D'] = 10, a[(int)'F'] = 12;
	cin >> s >> ss >> t >> tt;
	if(s != t)cout << "0000" << '\n';
	else {
		cout << 1;
		x = (ss[0] - '0') * 10 + ss[1] - '0', y = (tt[0] - '0') * 10 + tt[1] - '0' ;
		if(x != y)cout << "000" << '\n';
		else {
			cout << 1;
			if(a[(int)ss[2]] % 2 != a[(int)tt[2]] % 2)cout << "00" << '\n';
			else {
				cout << 1;
				if(abs(a[(int)ss[2]] - a[(int)tt[2]]) == 2)cout << 1 << '\n';
				else cout << 0 << '\n';
			}
		}
	}
	return 0;
}
