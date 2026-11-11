#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,a=0,b=0;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2)
	{
		cout << '1';
	}
	else
	{
		cout << '0';
	}
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	if (c1==c2)
	{
		if (a==b)
		{
			cout << '1';
		}
		else
		{
			cout << '0';
		}
	}
	else
	{
		cout << '0';
	}
	if (c1==c2)
	{
		if (a==b)
	    {
		    if ((s1[2]=='A' || (s1[2]=='B' || s1[2]=='C')) && (s2[2]=='A' || (s2[2]=='B' || s2[2]=='C')))
		    {
		    	cout << '1';
			}
			else if ((s1[2]=='D' && s2[2]=='E') || (s1[2]=='E' && s2[2]=='D'))
			{
				cout << '1';
			}
			else
			{
				cout << '0';
			}
		}
		else
		{
			cout << '0';
		}
	}
	else
	{
		cout << '0';
	}
	if (c1==c2)
	{
		if (a==b)
	    {
	    	int c=s1[2]-'A';
	    	int d=s2[2]-'A';
		    if (abs(c-d)==1 && ((c!=2 && d!=3)&&(c!=3&&d!=2)))
		    {
		    	cout << '1';
			}
			else
			{
				cout << '0';
			}
		}
		else
		{
			cout << '0';
		}
	}
	else
	{
		cout << '0';
	}
	return 0;
}
