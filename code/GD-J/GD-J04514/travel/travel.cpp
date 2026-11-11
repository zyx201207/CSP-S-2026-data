#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;

bool fun1() { return c1 == c2; }

bool fun2() {
	string sub1 = s1.substr(0, 2), sub2 = s2.substr(0, 2);
	return (sub1 == sub2) && fun1();
}

bool fun3() { return ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) && fun2(); }

bool fun4() {
	if (fun3() == false) return false;
	char c = s1[2], cc = s2[2];
	return (c == cc+1 || c == cc-1);
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	cout << fun1() << fun2() << fun3() << fun4();
	
	return 0;
}
