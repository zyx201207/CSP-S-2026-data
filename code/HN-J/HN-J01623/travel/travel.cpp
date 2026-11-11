#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a1[2],b1[4],a2[2],b2[4];
	for(int i=0;i<2;i++)cin>>a1[i];
	for(int i=0;i<3;i++)cin>>b1[i];
	for(int i=0;i<2;i++)cin>>a2[i];
	for(int i=0;i<3;i++)cin>>b2[i];
	if(a1[0]==a2[0]&&a1[1]==a2[1])cout<<1;
	else 
	{
		for(int i=1;i<=4;i++) cout<<0;
		return 0; 
	}
	if(b1[0]==b2[0]&&b1[1]==b2[1])cout<<1; 
	else 
	{
		for(int i=1;i<=3;i++) cout<<0;
		return 0;
	 } 
	if(((b1[2]=='A'&&b2[2]=='B')||(b1[2]=='A'&&b2[2]=='C')||(b1[2]=='B'&&b2[2]=='C')||(b2[2]=='A'&&b1[2]=='B')||(b2[2]=='A'&&b1[2]=='C')||(b2[2]=='B'&&b1[2]=='C')||(b1[2]=='D'&&b2[2]=='F')||(b2[2]=='D'&&b1[2]=='F')))
	{
		cout<<1;
	}
	else 
	{
		for(int i=1;i<=2;i++) cout<<0;
		return 0;
	}
	if(b1[2]=='A'&&b2[2]=='B'||b1[2]=='B'&&b2[2]=='C'||b1[2]=='D'&&b2[2]=='F'||b2[2]=='A'&&b1[2]=='B'||b2[2]=='B'&&b1[2]=='C'||b2[2]=='D'&&b1[2]=='F')
	{
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
