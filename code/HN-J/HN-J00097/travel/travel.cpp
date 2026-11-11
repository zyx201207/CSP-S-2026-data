#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag = (c1 == c2);
	cout << flag;
	flag &= (s1[0] == s2[0] && s1[1] == s2[1]);
	cout << flag;
	bool f1 = false, f2 = false;
	if(s1[2] >= 'A' && s1[2] <= 'C') f1 = false;
	else f1 = true;
	if(s2[2] >= 'A' && s2[2] <= 'C') f2 = false;
	else f2 = true;
	flag &= (f1 == f2);
	cout << flag;
	if(abs(s1[2] - s2[2]) != 1)
	{
		flag &= ((s1[2] == 'D' && s2[2] == 'F') || 
				(s1[2] == 'F' && s2[2] == 'D'));
	}
	cout << flag;
	return 0;
}
