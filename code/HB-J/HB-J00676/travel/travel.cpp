#include <iostream>
#include <cmath>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

string c1, s1, c2, s2;
string p1, p2;
char z1, z2;

bool check1() {
	return c1 == c2;
}

bool check2() {
	return check1() && p1 == p2;
}

bool check3() {
	bool fl = (z1 <= 'C' && z2 <= 'C') ||
			  (z1 >= 'D' && z2 >= 'D');
	return check2() && fl;
}

bool check4() {
	bool fl = (abs(z1 - z2) == 1) ||
			  (z1 == 'D' && z2 == 'F') ||
			  (z1 == 'F' && z2 == 'D');
	return check3() && fl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	p1 = s1[0] + s1[1], p2 = s2[0] + s2[1];
	z1 = s1[2], z2 = s2[2];
	
	cout << check1() << check2() << check3() << check4();
	return 0;
}
