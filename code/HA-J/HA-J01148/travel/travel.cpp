#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	bool pd=0;
	if(c1==c2)
	{
		cout<<"1";
		pd=1;
	}
	else cout<<"0";
	
	bool pd1=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&pd==1)
	{
		cout<<"1";
		pd1=1;
	}
	else cout<<"0";
	bool pd2=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			if(pd1==1)
			{
				cout<<"1";
				pd2=1;
			}
			else cout<<"0";
		}else cout<<"0";
	}
	else if(s1[2]=='D'||s1[2]=='F')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			if(pd1==1)
			{
				cout<<"1";
				pd2=1;
			}
			else cout<<"0";
		}else cout<<"0";
	}
	
	if(s1[2]=='A')
	{
		if(s2[2]=='B')
		{
			if(pd2==1)
			{
				cout<<"1";
			}
			else cout<<"0";
		}else cout<<"0";
	}
	else if(s1[2]=='B')
	{
		if(s2[2]=='A')
		{
			if(pd2==1)
			{
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(s2[2]=='C')
		{
			if(pd2==1)
			{
				cout<<"1";
			}
			else cout<<"0";
		}else cout<<"0";
	}
	else if(s1[2]=='C')
	{
		if(s2[2]=='B')
		{
			if(pd2==1)
			{
				cout<<"1";
			}
			else cout<<"0";
		}else cout<<"0";
	}
	else if(s1[2]=='D')
	{
		if(s2[2]=='F')
		{
			if(pd2==1)
			{
				cout<<"1";
			}
			else cout<<"0";
		}else cout<<"0";
	}
	else if(s1[2]=='F')
	{
		if(s2[2]=='D')
		{
			if(pd2==1)
			{
				cout<<"1";
			}
			else cout<<"0";
		}else cout<<"0";
	}
	return 0;
}
