#include<bits/stdc++.h>
using namespace std;
char b1[105],b2[105];
int a1,a2,s=0,k=0,q=0,w=0,e=0,r=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		cout<<"1";
	}
	else
		cout<<"0";
	s+=b1[3];
	k+=b2[3];
	q+=b1[1];
	w+=b2[1];
	e+=b1[2];
	r+=b2[2];
	if(q==w&&e==r&&s!=k)
	{
		cout<<"1";
	}
	else
		cout<<"0";
	if(q==w&&e==r)	
	{
		if(s=='A'&&k=='B'||s=='A'&&k=='C'||s=='B'&&k=='A'||s=='C'&&k=='A'||s=='B'&&k=='C'||s=='C'&&k=='B'||s=='D'&&k=='F'||s=='F'&&k=='D')
		{
			cout<<"0";
		}
	}
	else
		cout<<"1";
	if(q==w&&e==r)	
	{
		if(s=='A'&&k=='B'||s=='B'&&k=='A'||s=='B'&&k=='C'||s=='C'&&k=='B'||s=='D'&&k=='F'||s=='F'&&k=='D')
		{
			cout<<"0";
		}
	}
	else
		cout<<"1";	
	return 0;
} 
