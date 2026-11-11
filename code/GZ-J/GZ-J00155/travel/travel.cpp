//Àî¼ÎÁú GZ-J00155 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool f = 0;
	f = (c1 == c2);
	cout << f;
	string a, b;
	a = s1[0] + s1[1];
	b = s2[0] + s2[1];
	
	if (f)
	{
		f = (a == b);
		
	}
	cout << f;
	bool n = 0;
	
	if (f)
	{
		
		if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
		{
			if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') n = 1;
		}
		else if (s1[2] == 'D' || s1[2] == 'F')
		{
			if (s2[2] == 'D' || s2[2] == 'F') n = 1;
		}
	}
	
	cout << n;
	int m, t;
	if(n)
	{
		m = s1[2] - s2[2];
		t = s2[2] - s1[2];
		n = (m == 1 || t == 1);
		
	}
	cout << n;
	return 0;
}
