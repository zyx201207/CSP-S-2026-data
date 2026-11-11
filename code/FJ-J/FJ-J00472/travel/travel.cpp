#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2, l1, l2, n1, n2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	l1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	l2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	n1 = s1[2] - 'A'; n2 = s2[2] - 'A';
	bool f1 = (c1 == c2), f2 = (l1 == l2);
	bool f3 = (n1 <= 2 && n2 <= 2 || n1 >= 3 && n2 >= 3);
	bool f4 = (n1 - n2 == 1 || n1 - n2 == -1);
	if (f1) cout << 1;
	else cout << 0;
	if (f1 && f2) cout << 1;
	else cout << 0;
	if (f1 && f2 && f3) cout << 1;
	else cout << 0;
	if (f1 && f2 && f3 && f4) cout << 1;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
