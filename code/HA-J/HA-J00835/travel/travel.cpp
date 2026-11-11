#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=1,b=1,c=1,d=1;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			a=0;
			b=0;
			c=0;
			d=0;
		}
	}
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			b=0;
			c=0;
			d=0;
		}
	}
	if(s1[2]!='D'&&s2[2]!='F'&&s2[2]!='D'&&s2[2]!='F')
		{
			if((s1[2]-s2[2])<-1||s1[2]-s2[2]>1)
				d=0;
		}
	else
		{
			c=0;
			d=0;
		}	
	if(s1[2]=='D'&&s2[2]!='F')
		{
			c=0;
			d=0;
		}
			
	if(s1[2]=='F'&&s2[2]!='D')
		{
			c=0;
			d=0;
		}	
					
	if(a==1)
		cout<<"1";
	else
		cout<<"0";
	if(b==1)
		cout<<"1";
	else
		cout<<"0";
	if(c==1)
		cout<<"1";
	else
		cout<<"0";
	if(d==1)
		cout<<"1";
	else
		cout<<"0";		
	return 0;
}
