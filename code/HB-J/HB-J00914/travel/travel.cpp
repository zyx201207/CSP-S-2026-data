#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2?"1":"0");
	string p1,p2;
	p1+=s1[0],p1+=s1[1];
	p2+=s2[0],p2+=s2[1];
	cout<<(p1==p2&&c1==c2?"1":"0");
	char b1=s1[2],b2=s2[2];
	bool q1,q2;
	if(b1=='A'||b1=='B'||b1=='C')
	{
		q1=1;
	}
	else
	{
		q1=0;
	}
	if(b2=='A'||b2=='B'||b2=='C')
	{
		q2=1;
	}
	else
	{
		q2=0;
	}
	bool c=(q1==q2&&p1==p2&&c1==c2);
	cout<<c;
	bool i;
	if(c1==c2&&p1==p2&&q1==q2)
	{
		if((b1+1==b2||b2+1==b1))
			i=1;
		else
			i=0;
	}
	else
		i=0;
	cout<<i;
	return 0;
}
//02 02B 02 01A 1000
//02 01A 03 01A 0000
