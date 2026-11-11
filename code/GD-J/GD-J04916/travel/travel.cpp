#include<bits/stdc++.h>
using  namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string train[2];
	string seat[2];
	string s1;
	string s2;
	for(int i=0;i<=1;i++)
	{
		cin>>s1;
		train[i]=s1;
		cin>>s2;
		seat[i]=s2;
	}
	if(train[0]==train[1])
		cout<<'1';
	else
	{
		cout<<"0000";
		return 0;
	}
	if(seat[0][1]==seat[1][1])
	{
		cout<<'1';
		if(seat[0][2]>='D' && seat[1][2]>='D' && seat[1][2]!=seat[0][2])
		{
			cout<<"11";
		}		
		else if(seat[0][2]<='C' && seat[1][2]<='C' && seat[1][2]!=seat[0][2])
		{
			cout<<'1';
			if(abs(seat[1][2]-seat[0][2])==1)
				cout<<'1';
			else
				cout<<'0';
		}
		else
			cout<<"00";
	}
	else
	{
		cout<<"000";
	}
	return 0;
 } 
