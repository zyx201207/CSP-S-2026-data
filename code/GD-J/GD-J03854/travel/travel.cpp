#include<bits/stdc++.h>
using namespace std;
string s,f;
int a,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>s;
	cin>>d;
	cin>>f;
	if(a==d)
	{
		cout<<1;
		if(s[0]*10+s[1]==f[0]*10+f[1])
		{
			cout<<1;
			if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(f[2]=='A'||f[2]=='B'||f[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(f[2]=='D'||f[2]=='F')))
			{
				cout<<1;
				if(abs(s[2]-f[2])==1||(s[2]=='D'&&f[2]=='F')||(f[2]=='D'&&s[2]=='F'))
				cout<<1;
				else
				cout<<0;
			}
			else
			cout<<0<<0;
		}
		else
		cout<<0<<0<<0;
	}
	else
	cout<<0<<0<<0<<0;
	return 0;
 } 
