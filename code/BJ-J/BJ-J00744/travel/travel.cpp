#include <iostream>
using namespace std;

string c1, s1, c2, s2;
int x;
char t1, t2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	t1 = s1[2], t2 = s2[2];
	s1 = s1[0] + s1[1], s2 = s2[0] + s2[1];
	x = abs(t1 - t2);
	if ((t1 >= 'D') != (t2 >= 'D')) ++x;
	cout << (c1 == c2) << (c1 == c2 && s1 == s2) << (c1 == c2 && s1 == s2 && ((t1 >= 'D') == (t2 >= 'D'))) << (c1 == c2 && s1 == s2 && x == 1) << '\n';
	return 0;
}