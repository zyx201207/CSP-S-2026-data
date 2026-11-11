#include <bits/stdc++.h>
using namespace std;

string x1,y1,x2,y2,z1="",z2="";
int a[4];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>y1>>x2>>y2;
	z1=z1+y1[0]+y1[1];
	z2=z2+y2[0]+y2[1];
	if(x1==x2) a[0]=1;
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(z1==z2) a[1]=1;
	else
	{
		cout<<"1000"<<endl;
		return 0;
	}
	if(y1[2]<='C'&&y2[2]<='C'||y1[2]>='D'&&y2[2]>='D') a[2]=1;
	else
	{
		cout<<"1100"<<endl;
		return 0;
	}
	if(y1[2]=='A'&&y2[2]=='C'||y1[2]=='C'&&y2[2]=='A') a[3]=0;
	else a[3]=1;
	for(int i=0;i<4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
