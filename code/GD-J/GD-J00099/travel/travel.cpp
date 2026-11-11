#include <bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char s11,s22;
bool p;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>s11>>c2>>s2>>s22;
	if(s11=='C'&&s22=='D')
	{
		 p=1;
	}
	if(s22=='C'&&s11=='D')
	{
		 p=1;
	}
	
	
	
	if(c1==c2)
	{
		cout<<"1";
		if(s1==s2)
		{
			cout<<"1";
			
		}
		else
		{
			cout<<"0";
		}
		if(s1==s2&&p==0)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		if((s11-1==s22||s11+1==s22)&&s1==s2&&p==0)
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
		cout<<"000";
		if((s11-1==s22||s11+1==s22)&&s1==s2&&p==0)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	return 0;
}
