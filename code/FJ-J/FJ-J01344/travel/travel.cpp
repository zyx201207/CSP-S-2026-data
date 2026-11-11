#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int q1 = 0;
	if(c1 == c2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
		q1 = 1;
	}
	int z1,z2;
	if(s1[0] == '0')
	{
		z1 = (s1[1] - '0');
	}
	else
	{
		z1 = 10 + (s1[1] - '0');
	}
	if(s2[0] == '0')
	{
		z2 = (s2[1] - '0');
	}
	else
	{
		z2 = 10 + (s2[1] - '0');
	}
	int q2 = 0;
	if(z1 == z2 && q1 != 1)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
		q2 = 1;
	}
	int zb1,zb2;
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
	{
		zb1 = 1;
	}
	else
	{
		zb1 = 2;
	}
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
	{
		zb2 = 1;
	}
	else
	{
		zb2 = 2;
	}
	if(zb1 == zb2 && q1 != 1 && q2 != 1)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(zb1 == 2 && zb2 == 2 && q1 != 1 && q2 != 1)
	{
		cout << 1 << endl;
		return 0;
	}
	else if((s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'C' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'C') && q1 != 1 && q2 != 1)
	{
		cout << 1 << endl;
		return 0;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
} 
