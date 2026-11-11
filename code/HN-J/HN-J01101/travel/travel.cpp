#include <bits/stdc++.h>
using namespace std;
string c1 , c2 , s1 , s2;
int a , b , c , d , e , f;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a = (c1[0] - '0') * 10 + (c1[1] - '0');
	b = (s1[0] - '0') * 10 + (s1[1] - '0');
	c = s1[2] - 'A' + 1;
	d = (c2[0] - '0') * 10 + (c2[1] - '0');
	e = (s2[0] - '0') * 10 + (s2[1] - '0');
	f = s2[2] - 'A' + 1;
	if(a != d)
	{
		cout << "0000";
		return 0;
	}
	if(b != e)
	{
		cout << "1000";
		return 0;
	}
	if((c <= 3 && f >= 4) || (c >= 4 && f <= 3))
	{
		cout << "1100";
		return 0;
	}
	if(abs(c - f) != 1)
	{
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
