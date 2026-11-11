#include<bits/stdc++.h>
using namespace std;


string c1, c2, s1, s2;
int nc1, nc2, ns1, ns2, l, r;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0] == '0')
	{
		nc1 = c1[1] - '0';
	}
	else
	{
		nc1 = 10 + (c1[1] - '0');
	}
	if(c2[0] == '0')
	{
		nc2 = c2[1] - '0';
	}
	else
	{
		nc2 = 10 + (c2[1] - '0');
	}
	if(s1[0] == '0')
	{
		ns1 = s1[1] - '0';
	}
	else
	{
		ns1 = 10 + (s1[1] - '0');
	}
	if(s2[0] == '0')
	{
		ns2 = s2[1] - '0';
	}
	else
	{
		ns2 = 10 + (s2[1] - '0');
	}
	l = s1[2] - 'C';
	r = s2[2] - 'C';
	cout << (nc1 == nc2) << (nc1 == nc2 && ns1 == ns2) << (nc1 == nc2 && ns1 == ns2 && ((l <= 0 && r <= 0) || (l > 0 && r > 0))) << (ns1 == ns2 && ((l <= 0 && r <= 0) || (l > 0 && r > 0)) && abs(l - r) == 1);
	return 0;
}
