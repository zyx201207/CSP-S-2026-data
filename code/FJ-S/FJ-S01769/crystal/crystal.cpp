#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	long long n,m,a[500001],b[500001],c[500001],d,maxn;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		for(int j=1;j<=i-1;j++)
		{
			if(a[i]<a[j])
			{
				d=a[j];
				a[j]=a[i];
				a[i]=d;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=0)
		b[i]=0;
		for(int j=1;j<=i-1;j++)
		b[i]+=a[i]-a[j];
		if(b[i]>m)
		{for(int l=1;l<=i-1;l++)
		{
			b[i]-=a[l];
			if(b[i]<=m)
			{
				c[i]=i-l+1;
				l=i-1;
			}
		}
		}
		else
		c[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		maxn=max(c[i],maxn);
	}
	cout<<maxn<<endl;
	return 0;
}
