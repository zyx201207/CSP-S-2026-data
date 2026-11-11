#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string c1, s1, c2, s2, t1, t2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "W", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2);
	t1 = s1.substr(0,s1.size()-1);
	t2 = s2.substr(0,s2.size()-1);       
	char x = s1[s1.size()-1], y = s2[s2.size()-1];
	cout << (c1 == c2 && t1 == t2);
	cout << (c1 == c2 && t1 == t2 &&( (x <= 'C'&& y <= 'C')||( x >'C'&& y > 'C')));
	cout << (c1 == c2 && t1 == t2 &&( (x <= 'C'&& y <= 'C')||( x >'C'&& y > 'C')) && (x == y-1 || x == y+1));
	return 0;
}
