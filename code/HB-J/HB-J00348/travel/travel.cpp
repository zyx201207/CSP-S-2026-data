#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,c,d;
string a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n!=m)
	{
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	u+=a[0]-'0',u*=10,u+=a[1]-'0';
	v+=b[0]-'0',v*=10,v+=b[1]-'0';
	if(u==v) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	c=a[2]-'A'+1,d=b[2]-'A'+1;
	if(c==1)
	{
		if(d==2 || d==3) cout<<"1";
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(c==2)
	{
		if(d==1 || d==3) cout<<"1";
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(c==3)
	{
		if(d==1 || d==2) cout<<"1";
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(c==4)
	{
		if(d==6) cout<<"1";
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(c==6)
	{
		if(d==4) cout<<"1";
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(c==1)
	{
		if(d==2) cout<<"1";
		else
		{
			cout<<"0";
			return 0;
		}
	}
	if(c==2)
	{
		if(d==1 || d==3) cout<<"1";
		else
		{
			cout<<"0";
			return 0;
		}
	}
	if(c==3)
	{
		if(d==2) cout<<"1";
		else
		{
			cout<<"0";
			return 0;
		}
	}
	if(c==4)
	{
		if(d==6) cout<<"1";
		else
		{
			cout<<"0";
			return 0;
		}
	}
	if(c==6)
	{
		if(d==4) cout<<"1";
		else
		{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
