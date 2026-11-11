#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("fravel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool al=1,bl=1,cl=1;
	if(a==c)//是否在同一车厢 
	{
		cout<<1;	
	}	
	else
	{
		al=0;
		cout<<0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&al)//是否在同一行
	{
		cout<<1;
	} 
	else
	{
		bl=0;
		cout<<0;
	}
	if((b[2]-'A'<=2&&d[2]-'A'<=2&&bl)||(b[2]-'A'>2&&d[2]-'A'>2&&bl))//是否在同一侧
	{
		cout<<1;
	} 
	else
	{
		cl=0;
		cout<<0;
	}
	if(cl&&abs(b[2]-d[2])==1)//是否相邻 
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
