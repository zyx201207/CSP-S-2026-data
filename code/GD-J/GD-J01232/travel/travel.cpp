#include <bits/stdc++.h>
using namespace std;

int main()
{
	string n;
	string nh;
	string m;
	string mh;
	bool b1=0,b2=0,b3=0,b4=0;
	cin>>n>>nh>>m>>mh;
	if(n==m&&m!="01"&&n!="01"&&m!="16"&&n!="16")
	{
		b1=1;
	}
	if(b1)
	{
		if(mh[1]==nh[1])
		{
			b2=1;
		}
	}
	if(b1&&b2)
	{
		if((mh[2]=='A'&&nh[2]=='B')||(mh[2]=='A'&&nh=='C')||(mh[2]=='B'&&nh[2]=='A')||(mh[2]=='B'&&nh=='C')||(mh[2]=='C'&&nh[2]=='B')||(mh=='C'&&nh=='A')||(mh[2]=='D'&&nh=='F')||(mh[2]=='F'&&mh[2]=='D'))
		{
			b3=1;
		}
	}
	if(b1&&b2&&b3)
	{
		if((mh[2]=='A'&&nh[2]=='B')||(mh[2]=='B'&&nh[2]=='A')||(mh[2]=='B'&&nh=='C')||(mh[2]=='C'&&nh[2]=='B')||(mh[2]=='D'&&nh=='F')||(mh[2]=='F'&&mh[2]=='D'))
		{
			b4=1;
		}
	}
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
