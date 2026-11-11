#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int h,n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n==m)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<"1";	
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(65>=int(a[2])<=67 && 65>=int(a[2])<=67)
	{
		cout<<"1";
		h=1;
	}
	else
	{
		if('D'>=a[2]<='F'&&'D'>=a[2]<='F')
		{
			cout<<"1";
			h=2;
		}
		else
		{
			cout<<"00"<<endl;
			h=0;
		}
	}
	if(h==1||h==2)
	{
		if(abs(int(a[2])-int(b[2]))==1)
		{
			cout<<"1"<<endl;
		}
		else
		{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
