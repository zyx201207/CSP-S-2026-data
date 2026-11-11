//GZ-J00311 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x,y,xx,yy;
    cin>>x>>y>>xx>>yy;
    if(x==xx)
    {
    	cout<<1;
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(y[1]==yy[1]&&y[0]==y[0])
	{
		cout<<1;
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if((y[2]=='F'&&yy[2]=='D')||(y[2]=='D'&&yy[2]=='F')||(y[2]=='C'&&(yy[2]=='B'||yy[2]=='A'))||(y[2]=='B'&&(yy[2]=='C'||yy[2]=='A'))||(y[2]=='A'&&(yy[2]=='C'||yy[2]=='B')))
	{
		cout<<1;
	}
	else 
	{
		cout<<"00";
		return 0;
	}
	if((y[2]=='F'&&yy[2]=='D')||(y[2]=='D'&&yy[2]=='F')||(y[2]=='C'&&yy[2]=='B')||(y[2]=='B'&&(yy[2]=='C'||yy[2]=='A'))||(y[2]=='A'&&yy[2]=='B'))
	{
		cout<<1;
	}
	else 
	{
		cout<<"0";
		return 0;
	}
	return 0;
}
