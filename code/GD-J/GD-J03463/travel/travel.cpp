#include <iostream>
#include <string>
using namespace std;

string s1, c1, s2, c2;
string l1, l2; int o1, o2;
bool a1, a2, a3, a4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> c1 >> s2 >> c2;
	l1 = c1.substr(0, 2), l2 = c2.substr(0, 2), o1 = c1[2], o2 = c2[2];
	a1 = (s1 == s2);
	a2 = a1 && (l1 == l2);
	a3 = a2 && ((o1 <= 'C' && o2 <='C') || (o1 > 'C' && o2 > 'C'));
	a4 = a3 && ((o1 == o2 + 1) || (o2 == o1 + 1));
	cout << a1 << a2 << a3 << a4;
	return 0;
}

