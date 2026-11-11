#include <bits/stdc++.h>
using namespace std;
string a1, a2, b1, b2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	bool v = a1 == b1, x = v && a2.substr(0, 2) == b2.substr(0, 2),
	y = x && ((char(a2[2]) > 'C') ^ (char(b2[2]) < 'D')),
	z = y && (abs(char(a2[2]) - char(b2[2])) == 1 || char(min(a2[2], b2[2])) == 'D');
	cout << v << x << y << z;
	return 0;
}
//freopen("travel.in", "r", stdin);
//freopen("travel.out", "w", stdout);
