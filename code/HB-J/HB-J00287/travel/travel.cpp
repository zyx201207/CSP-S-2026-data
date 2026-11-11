#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string t1 = s1.substr(0, 2);
	string t2 = s2.substr(0, 2);
	char st1 = s1[2], st2 = s2[2];
	bool a = (c1 == c2);
	bool b = (c1 == c2 && t1 == t2);
	bool c = !((st1 == 'F' && st2 != 'D') || (st1 != 'F' && st2 == 'D'));
	bool d = ((abs(st2 - st1) == 1) || (st1 == 'D' && st2 == 'F') || (st1 == 'F' && st2 == 'D'));
	cout << a << (a && b) << (a && b && c) << (a && b && c && d);
	return 0;
}
