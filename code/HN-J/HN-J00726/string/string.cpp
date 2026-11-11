#include <bits/stdc++.h>
using namespace std;
int cnt=0;
string hum,nu,nj;
int Str(int x,char y)
{
	cin>>x>>y;
	for(int i=1;i<=x;i++)
	{
		hum[i]=y;
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	cin>>n;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		Str(a,c);
	}
	if(hum.size/2==0)
	{
		nu=hum[1]~hum[hum.size/2];
		nj=hum-nu;
		if(nu==nj)
		{
			cout<<cnt;
		}
		else if(nu!=nj)
		{
			for(int i=1;i<=n;i++)
			{
				nu
			}
		}
	}
	else if(hum.size/2==1)
	{
		
	}
	return 0;
}
