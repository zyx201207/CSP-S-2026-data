#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int t=0,m=s1.size()-1,n=s2.size()-1;
	if(c1==c2)
	{
		cout<<'1'; 
	}
	else
	{
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
	for(int i=0;i<s1.length()-1;i++)
	{
		if(s1[i]!=s2[i])
		{
			t=1;
		}
	}
	if(t==0)
	{
		cout<<'1';
		if(s1[m]>='A'&&s1[m]<='C'&&s2[n]>='A'&&s2[n]<='C')
		{
			cout<<'1';
			if((s1[m]=='A'&&s2[n]=='B')||(s1[m]=='B'&&(s2[n]=='A'||s2[n]=='C'))||(s1[m]=='C'&&s2[n]=='B'))
			{
				cout<<'1';
			}
			else
			{
				cout<<'0';
			}
		}
		if(s1[m]>='D'&&s1[m]<='F'&&s2[n]>='D'&&s2[n]<='F')
		{
			cout<<'1'<<'1';
		}
	}
	if(t==1)
	{
		cout<<'0'<<'1';
	}
	return 0;
}
