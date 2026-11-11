//GZ-J00509 взО§КЦ КывужабЇ 
#include<bits/stdc++.h>
using namespace std;
long long n,m,zd,a[200010],h[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			zd=max(zd,a[i]);
		}
	}
	if(m==n)
	{
		zd=a[1];
		for(int i=1;i<=n;i++)
		{
			zd=zd&a[i];
		}
		
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			h[i]=a[i]&a[i-1];
		} 
		for(int i=1;i<=n;i++)
		{
			zd=max(zd,h[i]);
		}
	}
	cout<<zd;
	return 0;
}
