#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool check(string s,string z)
{
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]!=z[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(check(s1,s3))
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	for(int i=0; i<s2.size()-1; i++)
	{
		if(s2[i]!=s4[i])
		{
			cout << "000";
			return 0;
		}
	}
	cout << 1;
	if(s2[2]=='D' || s2[2]=='F')
	{
		if(s4[2]!='D' && s4[2]!='F')
		{
			cout << "00";
			return 0;
		}
		else
		{
			cout << "11";
			return 0;
		}
	}
	else
	{
		if(s4[2]=='F' || s4[2]=='D')
		{
			cout << "00" << endl;
			return 0;
		}
		else
		{
			cout << 1;
			if(s2[2]=='A')
			{
				if(s4[2]!='B')
				{
					cout << 0;
					return 0;
				}
				else
				{
					cout << 1;
					return 0;
				}
			}
			if(s2[2]=='B')
			{
				if(s4[2]!='A' || s4[2]!='C')
				{
					cout << 0;
					return 0;
				}
				else
				{
					cout << 1;
					return 0;
				}
			}
			
			if(s2[2]=='C')
			{
				if(s4[2]!='B')
				{
					cout << 0;
					return 0;
				}
				else
				{
					cout << 1;
					return 0;
				}
			}
			
		}
	}
	return 0;
}
