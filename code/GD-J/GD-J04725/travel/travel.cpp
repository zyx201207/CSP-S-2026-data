#include<bits/stdc++.h> 
using namespace std;
string a,b,a1,b1;
int main()
{
	freopen("travel.in","r","std.in");
	freopen("travel.out","w","std.out");
	cin>>a>>a1>>b>>b1;
	if(a==b)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	string x,y;
	char x1,y1;
	x+=a1[0]+a1[1];
	y+=b1[0]+b1[1];
	x1+=a1[2];
	y1+=b1[2];
	if(x==y)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(((x1=='A'||x1=='B'||x1=='C')&&(y1=='A'||y1=='B'||y1=='C'))||((x1=='D'||x1=='F')&&(y1=='D'||y1=='F')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	char w,e;
	w=char(int(x1)+1);
	e=char(int(x1)+1);
	if(w==y1||e==y1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
} 
