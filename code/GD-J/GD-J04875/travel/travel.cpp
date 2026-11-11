#include <bits/stdc++.h>
using namespace std;
int st[] = {1, 1, 1, 2, 2};
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
		cout << 1;
	else
		cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
		cout << 1;
	else
		cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]
	&& st[int(s1[2]-65)] == st[int(s2[2]-65)])
		cout << 1;
	else
		cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]
	&& abs(int(s1[2] - s2[2])) == 1)
		cout << 1;
	else
		cout << 0;
	return 0;
}

