#include <bits/stdc++.h>
using namespace std;

int a[100005];

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	a[int('A')] = a[int('B')] = a[int('C')] = 1;
	a[int('D')] = a[int('F')] = 2;
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(int(s1 == s3))
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	int p1, p2;
	p1 = stoi(s2.substr(0, 2));
	p2 = stoi(s4.substr(0, 2));
	if(int(p1 == p2))
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	char c1, c2;
	c1 = s2[2];
	c2 = s4[2];
	if(int(a[int(c1)] == a[int(c2)]))
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	int num = c1 + c2;
	cout << int(num == 'A' + 'B' || num == 'B' + 'C' || num == 'D' + 'F');
	return 0;
}
