#include <bits/stdc++.h>
using namespace std;
int s1m[25],s2m[25];
string s1s,s2s;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,cnts1=0,cnts2=0,cnts1s=0,cnts2s=0;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i=0;i<s1.length();i++)
	{
		if (s1[i]>='0'&&s1[i]<='9')
		{
			cnts1++;
			s1m[cnts1]=s1[i]-'0';
		}
	}
	for (int i=0;i<s2.length();i++)
	{
		if (s2[i]>='0'&&s2[i]<='9')
		{
			cnts2++;
			s2m[cnts2]=s2[i]-'0';
		}
	}
	for (int i=0;i<s1.length();i++)
	{
		if (s1[i]>='A'&&s1[i]<='F')
		{
			cnts1s++;
			s1s[cnts1s]=s1[i];
		}
	}
	for (int i=0;i<s2.length();i++)
	{
		if (s2[i]>='A'&&s2[i]<='F')
		{
			cnts2s++;
			s2s[cnts2s]=s2[i];
		}
	}
	if (c1==c2)
	{
		cout <<"1";
		for (int i=1;i<=cnts1;i++)
		{
			if (s1m[i]!=s2m[i])
			{
				cout <<"000";
				return 0;
			}
		}
		cout <<"1";
		for (int i=1;i<=1;i++)
		{
			if (((s1s[i]=='A'||s1s[i]=='B'||s1s[i]=='C')&&(s2s[i]=='A'||s2s[i]=='B'||s2s[i]=='C'))||((s1s[i]=='D'||s1s[i]=='F')&&(s2s[i]=='D'||s2s[i]=='F')))
			{
				cout <<"1";
				if (s1s[i]=='D'||s1s[i]=='F')
				{
					cout << "1";
					return 0;
				}
				else if((s1s[i]=='A'&&s2s[i]=='B')||(s1s[i]=='B'&&(s2s[i]=='A'||s2s[i]=='C'))||(s1s[i]=='C'&&s2s[i]=='B'))
				{
					cout <<"1";
					return 0;
				}
				cout << "0";
			}
			else
			{
				cout <<"00"; 
				return 0;
			}
		}
	}
	else 
	{
		cout << 0000;
		return 0;
	}
	return 0;
}
