#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool d=0,e=0,f=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		d=1;
		cout<<"1";
	}
	else cout<<"0";
	
	if(d)
	{
		if(s1[0]==s2[0] and s1[1]==s2[1])
		{
			e=1;
			cout<<"1";
		}
		else cout<<"0";
	}
	else cout<<"0";
	
	if(e)
	{
		if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C')
		{
			if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C')
			{
				f=1;
				cout<<"1";
			}
			else cout<<"0";
		}
		if(s1[2]=='D' or s1[2]=='F')
		{
			if(s2[2]=='D' or s2[2]=='F')
			{
				f=1;
				cout<<"1";
			}
			else cout<<"0";
		}
	}
	else cout<<"0";
	
	if(f)
	{
		if((char)s1[2]+1==s2[2] or (char)s2[2]+1==s1[2]) cout<<"1";
		else cout<<"0";
	}
	else cout<<"0";
	return 0;
}
