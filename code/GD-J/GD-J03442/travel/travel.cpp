#include <bits/stdc++.h>
using namespace std;
string n1,n2,m1,m2;
int b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>m1>>n2>>m2;
	if(n1==n2)
	{
		cout<<"1";
	}
	//Trick||Treat!
	else
	{
		cout<<"0000";
		return 0;
	}
	b1=m1[0];
	b1=(b1-48)*10;
	b1+=m1[1];
	b1-=48;
	//
	b2=m2[0];
	b2=(b2-48)*10;
	b2+=m2[1];
	b2-=48;
	if(b1==b2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	int x1=m1[2],x2=m2[2];
	if(m1[2]>=65 && m1[2]<=67 && m2[2]>=65 && m2[2]<=67)
	{
		cout<<"1";
	}
	else if(m1[2]>=68 && m1[2]<=70 && m2[2]>=68 && m2[2]<=70)
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(m1[2]-m2[2]==1 || m1[2]-m2[2]==-1)
	{
		if(m1[2]==67 && m2[2]==68)
		{
			cout<<"0";
		}
		else if(m1[2]==68 && m2[2]==67)
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
	else if(m1[2]==68 && m2[2]==70)
	{
		cout<<"1";
	}
	else if(m1[2]==70 && m2[2]==68)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
 } 
