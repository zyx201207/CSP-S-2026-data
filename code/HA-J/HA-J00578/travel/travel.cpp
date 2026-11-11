#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,r1,x,x2;
	cin>>r>>r1>>x>>x2;
	if(r==x)
	cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	if(r1[0]==x2[0]&&r1[1]==x2[1])
	cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	
	if((r1[2]=='A')&&(x2[2]=='B'||x2[2]=='C')||(r1[2]=='B')&&(x2[2]=='A'||x2[2]=='C')||(r1[2]=='C')&&(x2[2]=='B'||x2[2]=='A')||(r1[2]=='D')&&(x2[2]=='F')||(r1[2]=='F')&&(x2[2]=='D'))
	cout<<1;
	else
	{
		cout<<0<<0;
		return 0;
	}
	
	if((r1[2]=='A')&&(x2[2]=='B')||(r1[2]=='B')&&(x2[2]=='A')||(r1[2]=='C')&&(x2[2]=='B')||(r1[2]=='B')&&(x2[2]=='C')||(r1[2]=='D')&&(x2[2]=='F')||(r1[2]=='F')&&(x2[2]=='D'))
	cout<<1;
	else
	cout<<0;
	return 0;
}
