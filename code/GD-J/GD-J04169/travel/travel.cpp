#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a=0,b=0,c=0,d=0;
	string c1,s1,c2,s2;
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	if(c1==c2)
	{
		a=1;
	}
	else
	{
		cout << a << b << c << d;
		return 0;
	}
	if(s1[0]*10+s1[1]*1==s2[0]*10+s2[1]*1)
	{
		b=1;
	}
	else
	{
		cout << a << b << c << d;
		return 0;
	}
	if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))
	{
		c=1;
	}
	else
	{
		cout << a << b << c << d;
		return 0;
	}
	if((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))
	{
		c=1;
	}
	else
	{
		cout << a << b << c << d;
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))//s1[2]-s2[2]==1||s2[2]-s1[2]==1
	{
		d = 1;
	}
	cout << a << b << c << d;
	return 0;
}
