#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,t1=0,t=0,ans=0000,t2=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans=1000;
		t1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]&&t1==1)
		{
			ans=1100;
			if(s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67)
			{
				ans=1110;
				t=1;
				if(t==1)
				{
					if(s1[2]-1==s2[2]||s1[2]+1==s2[2])
					ans=1111;	
				}
				else
					ans=1110;
			}			
			else if(s1[2]>=68&&s1[2]<=69&&s2[2]>=68&&s2[2]<=69)
			{
				ans=1110;
				t=1;
				if(t==1)
				{
					if(s1[2]-1==s2[2]||s1[2]+1==s2[2])
					ans=1111;	
				}
				else
					ans=1110;
			}			
			else
				ans=1100;
			
		}
		else
			ans=1000;
	}		
	else 
	{
		t2=1;
		cout<<"0000";
	}
	if(t2==0)	
	cout<<ans;
	return 0;
 } 
