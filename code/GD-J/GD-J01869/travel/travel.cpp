#include <bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool f1 = (c1 == c2), f2 = (s1.substr(0, 2) == s2.substr(0, 2)), f3 = ((s1[2] >= 'A' && s1[2] <='C') == (s2[2] >= 'A' && s2[2] <= 'C')), f4 = (abs((int)(s1[2]-s2[2])) == 1); 
	cout << f1;
	cout << (f1&&f2);
	cout << (f1&&f2&&f3);
	cout << (f1&&f2&&f3&&f4);
	return 0;
}
