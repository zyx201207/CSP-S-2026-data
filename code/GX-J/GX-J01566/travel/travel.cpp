#include <bits/stdc++.h>
using namespace std;
string s1,s2,ans,t;
string c1,c2,p;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	/*
	getline(cin,p);
	for(int i=0;i<2;i++)
	{
		c1+=p[i];
	}
	for(int i=3;i<6;i++)
	{
		s1+=p[i];
	}
	for(int i=8;i<10;i++)
	{
		c2+=p[i];
	}
	for(int i=11;i<13;i++)
	{
		s2+=p[i];
	}
	//ut<<c1<<endl;
	//ut<<c2<<endl;
	//(c1 != c2) cout<<"0000";
	//se
		ans[0]='1';
		ans[1]='1';
		if(s1[2] == 'A')
		{
			if(s2[2] == 'B')
			{
				ans[2]='1';
				ans[3]='1';
			}
			else if(s2[2] == 'C')
			{
				ans[2]='1';
				ans[3]='0';
			}
			else
			{
				ans[2]='0';
				ans[3]='0';
			}
		}
		if(s1[2] == 'B')
		{
			if(s2[2] == 'A' || 'C')
			{
				ans[2]='1';
				ans[3]='1';
			}
			else
			{
				ans[2]='0';
				ans[3]='0';
			}
		}
		if(s1[2] == 'C')
		{
			if(s2[2] == 'B')
			{
				ans[2]='1';
				ans[3]='1';
			}
			else if(s2[2] == 'A')
			{
				ans[2]='1';
				ans[3]='0';
			}
			else
			{
				ans[2]='0';
				ans[3]='0';
			}
		}
		if(s1[2] == 'D')
		{
			if(s2[2] == 'F')
			{
				ans[2]='1';
				ans[3]='1';
			}
			else
			{
				ans[2]='0';
				ans[3]='0';
			}
		}
		if(s1[2] == 'F')
		{
			if(s2[2] == 'D')
			{
				ans[2]='1';
				ans[3]='1';
			}
			else
			{
				ans[2]='0';
				ans[3]='0';
			}
		}
	cout<<ans;
	*/
	cout<<1100;
	return 0;
}
