#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100001],maxx,alll;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)alll=a[i];
		alll&=a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(m==1)cout<<maxx;
	else if(m==n)cout<<alll;
	else if(m==2)
	{
		maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(m==n-1)
	{
		//枚举不选的 
		maxx=0;
		for(int i=1;i<=n;i++)
		{
			long long gh=0;
			if(i==1)gh=a[2];
			else gh=a[1];
			for(int j=1;j<=n;j++)
			{
				if(j==i)continue;
				gh&=a[j];
			}
			maxx=max(maxx,gh);
		}
		cout<<maxx;
	}
	else//A
	{
		maxx=a[n];
		for(int i=n;i>=n-m+1;i--)
		{
			maxx&=a[i];
		}
		cout<<maxx;
	}
	return 0;
}
/*
我将窃取该学校所有人的运气并使得我能够获得一级认证 
*/
