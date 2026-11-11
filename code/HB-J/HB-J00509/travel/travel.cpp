#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		cout << 1;
	else
		cout << 0;
	if (c1 == c2 && s1[0] + s1[1] == s2[0] + s2[1])
		cout << 1;
	else
		cout << 0;
	if (c1 == c2 && s1[0] + s1[1] == s2[0] + s2[1])
	{
		int ss1 = 0,ss2 = 0;
		if (s1[2] == 'D' || s1[2] == 'F')
			ss1 = 1;
		if (s2[2] == 'D' || s2[2] == 'F')
			ss2 = 1;
		if (ss1 == ss2)
			cout << 1;
		else
			cout << 0;
	}
	else
		cout << 0;
	if (c1 == c2 && s1[0] + s1[1] == s2[0] + s2[1])
	{
		int ss1 = 0,ss2 = 0;
		if (s1[2] == 'D' || s1[2] == 'F')
			ss1 = 1;
		if (s2[2] == 'D' || s2[2] == 'F')
			ss2 = 1;
		if (ss1 == ss2)
		{
			if (s1[2] == 'F')
				s1[2] = 'E';
			if (s2[2] == 'F')
				s2[2] = 'E';
			int ss1 = s1[2] - 'A';
			int ss2 = s2[2] - 'A';
			if (abs(ss1 - ss2) == 1)
				cout << 1;
			else
				cout << 0;
		}
		else
			cout << 0;
	}
	else
		cout << 0;
	cout << endl;
	return 0;
}
