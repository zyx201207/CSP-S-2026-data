#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	getline(cin,s);
	if(s[1]==s[6]&&s[2]==s[7])
	{
		cout << 1;
		if(s[3]==s[8]&&s[4]==s[9])
	{
		cout << 1;
		if(s[5]=='A'||s[5]=='B'||s[5]=='C'&&(s[10]=='A'||s[10]=='B'||s[10]=='C'))
		{
			cout << 1;
    	}
    	else if(s[5]=='D'||s[5]=='F'&&(s[10]=='D'||s[10]=='F'))
		{
				cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
	}
	else
	{
		cout << 0;
	}
	
	if(s[1]==s[6]&&s[2]==s[7])
	{
		if(s[3]==s[8]&&s[4]==s[9])
		{
			if(s[5]=='A'&&s[10]=='B')
			{
					cout << 1;
			}
			else if(s[5]=='B'&&(s[10]=='A'||s[10]=='C'))
			{
				cout << 1;
			}
			else if(s[5]=='C'&&s[10]=='B')
			{
				cout << 1;
			}
			else if(s[5]=='D'&&s[10]=='F')
			{
				cout << 1;
			}
			else if(s[5]=='F'&&s[10]=='D')
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
	}
	return 0;
}
