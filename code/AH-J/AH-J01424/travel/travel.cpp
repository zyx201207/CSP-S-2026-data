#include<bits/stdc++.h>
using namespace std;
int a[5]={1,1,0,0};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++) 
	{
		if(c1[i]!=c2[i]) 
		{
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<2;i++) 
	{
		if(s1[i]!=s2[i]) 
		{
			cout<<a[0]<<0<<0<<0;
			return 0;
		}
	}
	if(s1[2]=='D'&&s2[2]=='F')
	{
		cout<<"1111";
		return 0;
	}
	else if(s2[2]=='D'&&s1[2]=='F')
	{
		cout<<"1111";
		return 0;
	}
	if(int(s1[2])<=67&&int(s2[2])<=67) 
	{
		a[2]=1;
		if(int(s1[2])-int(s2[2])==-1||int(s1[2])-int(s2[2])==1) a[3]=1;
	}
	for(int i=0;i<4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
