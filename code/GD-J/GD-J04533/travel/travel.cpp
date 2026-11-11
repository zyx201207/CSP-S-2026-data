#include<bits/stdc++.h>
using namespace std;
string ah,bh,p1="",p2="",gp1="",gp2="",lp1="",lp2="";
int ax,bx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>ah;
	cin>>bx>>bh;
	p1+=char(ah[0]);p1+=char(ah[1]);
	p2+=char(bh[0]);p2+=char(bh[1]);
	gp1=ah[2];
	gp2=bh[2];
	lp1=gp1;
	lp2=gp2;
	if(ax==bx)
	{
		if(p1==p2)
		{
			if((gp1<="C"&&gp2<="C"))
			{
				if((lp1=="A"&&lp2=="B")||(lp1=="B"&&lp2=="A")||(lp1=="B"&&lp2=="C")||(lp1=="C"&&lp2=="B"))
				{
					cout<<"1111";
					return 0; 
				}
				cout<<"1110";
				return 0;
			}
			if(gp1>="D"&&gp2>="D")
			{
				cout<<"1111";
				return 0;
			}
			cout<<"1100";
			return 0;
		}
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
