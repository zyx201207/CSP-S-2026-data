#include<bits/stdc++.h>
using namespace std;
string c[7],s[7];
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i = 1;i <= 2;i++)
	{
		cin >> c[i] >> s[i];
	}
	if(c[1]==c[2])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	
	s1=s[1];
	s2=s[2];
	 
	if(c[1]==c[2])
	{
		
	
		if(s1[0]==s2[0])
		{
			if(s1[1]==s2[1])
			{
				cout << 1;
			}
			else cout << 0;
		}
		else cout << 0;
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			
		
			if(s1[2]<='C' && s2[2]<='C')
			{
				cout << 1;
			}
			else
			{
				if(s1[2]>'C' && s2[2]>'C')
				{
					cout << 1;
				}
				else cout << 0;
			}
			if(s1[2]=='C' && s2[2]=='D' || s1[2]=='D' && s2[2]=='C')
			{
				cout << 0; 
			}
		
		
			else if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='B' && s2[2]=='A') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='F' && s2[2]=='D'))
			{
				cout << 1;
			}
			else cout << 0;
		}
		else cout << "00";
	}
	else cout << "000";
}
