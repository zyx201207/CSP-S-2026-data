#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int c;
	if (c1==c2)
	{
		c++;
	}
	if (s1[0,2]==s2[0,2])
	{
		c++;
	}
	if (((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C')&&((s2[2]=='A')||(s2[2]=='B')||(s2[2]=='C')))||(((s1[2]=='D')||(s1[2]=='F'))&&((s2[2]=='D')||(s2[2]=='F'))))
	{
		c++;
	}
	if ((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||(s2[2]=='C'&&s1[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F'))
	{
		c++;
	}
	for (int i=0;i<=c;i++)
	{
		cout << "1";
	}
	for (int i=1;i<4-c;i++)
	{
		cout << "0";
	}
	return 0;
}