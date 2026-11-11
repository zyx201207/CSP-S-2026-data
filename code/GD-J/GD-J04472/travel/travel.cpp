#include<iostream>
using namespace std;
int a[1005];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,x,x1;
	cin>>s>>s1>>x>>x1;
	a['D']=1;
	a['F']=1;
	if(s!=x)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(s1[0]==x1[0]&&s1[1]==x1[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(a[s1[2]]!=a[x1[2]])
	{
		cout<<"00";
		return 0;
	}
	else
	{
		
		cout<<"1";
		if(a[s1[2]]==1)
		{
			if(s1[2]=='D'&&x1[2]=='F')
			{
				cout<<"1";
			}
			else if(s1[2]=='F'&&x1[2]=='D')
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
		else
		{
			if(s1[2]+1==x1[2])
			{
				cout<<"1";
			}
			else if(x1[2]+1==s1[2])
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
	}
	return 0;
 } 
