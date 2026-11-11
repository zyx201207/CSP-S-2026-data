#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool f = false;
	bool f1 = false;
	bool f2 = false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		f=true;
	}
	else
	{
		cout<<"0000";		
	}
	if(f) 
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			f1=true;
		}
		else
		{
			cout<<"000";
		}
		if(f1)
		{
			if(((s1[2]=='A'||s1[2]=='B')||s1[2]=='C')&&((s2[2]=='A'||s2[2]=='B')||s2[2]=='C'))
			{
				f2=true;
				cout<<1;
			}
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
			{
				f2=true;
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))
			{
				cout<<0;
			}
			else if(((s1[2]+1==s2[2])||(s1[2]-1==s2[2]))||((s2[2]+1==s1[2])||(s2[2]-1==s1[2])))
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		
		
	}

	return 0;
} 
