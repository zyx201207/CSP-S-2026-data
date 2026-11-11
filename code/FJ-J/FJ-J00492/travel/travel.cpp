#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	{
		cout << "1";
	}
	else 
	{
		cout << "0000";
		return 0;
	}
	int p1,p2;
	p1 = (s1[0]-'0')*10+(s1[1]-'0');
	p2 = (s2[0]-'0')*10+(s2[1]-'0');
	if(p1==p2)
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if((s1[2]>='A'&&s1[2]<='C' && s2[2]>='A'&&s2[2]<='C') || (s1[2]=='D'||s1[2]=='F' && s2[2]=='D'&&s2[2]=='F'))
	{
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	int x = s1[2]-s2[2];
	if(abs(x) == 1)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}
