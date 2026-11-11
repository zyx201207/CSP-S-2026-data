#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1,s2;
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(s1/10!=s2/10)
	{
		cout<<"000";
	}
	else
	{
		cout<<"1";
	}
		 if(s1%10=='D'&&s2%10=='F')
		{
			cout<<"11";
			return 0;
			}
		else
		{	
			if(s2%10=='D'&&s1%10=='F')
		{
			cout<<"11";
			return 0;
			}
		if(s1%10-s2%10==1||s2%10-s1%10==1)
		{
			if(s2%10!='D'&&s1%10!='C')
			{
				if(s1%10!='D'&&s2%10!='C')
			{
				cout<<"11";
			}
			}
		}
	}
		
		
			if(s2%10=='A'&&s1%10=='C')
			{
				cout<<"10";
			}
			else
			{
				if(s1%10=='A'&&s2%10=='C')
			{
				cout<<"10";
			}
			
			else
			{
			cout<<"00";
		 }
	     }
         

	return 0;
}

