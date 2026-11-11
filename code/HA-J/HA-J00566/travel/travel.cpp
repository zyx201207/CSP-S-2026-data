#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2,m=0;
char x1,x2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>x1>>b1>>b2>>x2;
	if(a1==b1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a2==b2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(((int)x1<=67&&(int)x2<=67)||((int)x1>67&&(int)x2>67))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(((int)x1-(int)x2==1)||((int)x2-(int)x1==1))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
