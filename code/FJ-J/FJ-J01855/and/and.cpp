#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=0,hh;
	cin>>n>>m;
	int a[1000005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(i==1)
			hh=a[i];
		else
			hh=hh&a[i];
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		cout<<hh;
		return 0;
	}
	hh=a[1]&a[2];
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				hh=max(hh,a[i]&a[j]);
		cout<<hh;
		return 0;
	}
	return 0;
}
