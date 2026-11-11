#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[1]=1;
	}
	if((s1[0]-'0')*10+s1[1]-'0'==(s2[0]-'0')*10+s2[1]-'0'&&a[1]==1)
	{
		a[2]=1;
	}
	if(a[2]==1)
	{
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
		{
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
			{
				a[3]=1;
			}
		}
		if(s1[2]=='D'||s1[2]=='F')
		{
			if(s2[2]=='D'||s2[2]=='F')
			{
				a[3]=1;
			}
		}
	}
	if(a[3]==1)
	{
		if(s1[2]=='D'||s1[2]=='F'||s1[2]=='B')
		{
			a[4]=1;
		}
		else if(s2[2]=='B')
		{
			a[4]=1;
		}
	}
	for(long long i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
