#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x1,y1,x2,y2,z1,z2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=c1[0]-48;
	x1=x1*10+c1[1]-48;
	x2=c2[0]-48;
	x2=x2*10+c2[1]-48;
	y1=s1[0]-48;
	y1=y1*10+s1[1]-48;
	y2=s2[0]-48;
	y2=y2*10+s2[1]-48;
	z1=s1[2]-64;
	z2=s2[2]-64;
	if(x1==x2)
	cout<<"1";
	else
	cout<<"0";
	if(x1==x2&&y1==y2)
	cout<<"1";
	else
	cout<<"0";
	int f=1;
	if(x1==x2&&y1==y2)
	{
		if(z1>=1&&z1<=3&&z2>=1&&z2<=3)
		{
		cout<<"1";	
		f=0;
		}
		else if(z1>=4&&z1<=5&&z2>=4&&z2<=5)
		{
		f=0;
		cout<<"1";	
		}
		else
		cout<<"0";	
	}
	else
	cout<<"0";
	if(f==1)
	cout<<"0";
	else
	{
	 if(abs(z1-z2)==1)
	 cout<<"1";
	 else
	 cout<<"0";
	}
	return 0;
}
