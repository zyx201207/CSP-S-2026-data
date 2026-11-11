//GZ-J00560 陈俊达 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	string s,c,r,t,f,i;
	cin>>s>>c>>r>>t;
	if(s==r) 
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(c[0]==t[0]&&c[1]==t[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(c[2]=='C'&&t[2]=='D'||c[2]=='D'&&t[2]=='C')
	{
		cout<<"00";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	a=c[2];
	b=t[2];
	if(a-b==1||b-a==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
}
