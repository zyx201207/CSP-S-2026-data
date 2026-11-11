#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int b1,b2;
	b1=int(s1[2])-64;
	b2=int(s2[2])-64;
	int flag=0;
	int blag=0;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		blag=1;
	}
	if(s2[0]==s2[0]&&s1[1]==s2[1]&&blag==0)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		flag=1;
	}
	if(flag==0)
	{
	if(b1==1&&b2==2)
	{
		cout<<"1";
	}
	else if(b1==1&&b2==3)
	{
		cout<<"1";
	}
	else if(b1==2&&b2==3)
	{
		cout<<"1"<<endl;
	}
	else if(b2==2&&b1==3)
	{
		cout<<"1";
	}
	else if(b2==1&&b1==3)
	{
		cout<<"1";
	}
	else if(b2==1&&b1==2)
	{
		cout<<"1";
	}
	else if(b2==4&&b1==5)
	{
		cout<<"1";
	}
	else if(b1==5&&b2==4)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(b1==1&&b2==2)
	{
		cout<<"1";
	}
	else if(b1==2&&b2==1)
	{
		cout<<"1";
	}
	else if(b2==4&&b1==5)
	{
		cout<<"1";
	}
	else if(b1==5&&b2==4)
	{
		cout<<"1";
	}
	else if(b1==2&&b2==3)
	{
		cout<<"1";
	}
	else if(b2==2&&b1==3)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	}
	else
	{
		cout<<"0"<<"0";
	}
	
	return 0;
}
