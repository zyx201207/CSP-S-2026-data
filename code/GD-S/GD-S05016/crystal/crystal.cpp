#include<bits/stdc++.h>
using namespace std;
int n,m,max2,bh;
int a[500001];
int b;
int c[500001];
bool d[500001];
int xz(int x,int s,int nl)
{
	if(x==0||s<a[bh]-a[x])
	{
		return nl;
	}
	else
	{
	for(int i=x;i>=1;i--)
	{
		if(a[bh]-a[i]<=s&&d[i]==0)
		{
			d[i]=1;
			nl++;
			return xz(i-1,s-(a[bh]-a[i]),nl);
		}
	}	
	}
	return nl;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=n;j>=i;j--)
		{
			if(a[j]<=a[j-1])
			{
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=m)
			{
				c[i]++;
			}
			else
			{
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(max2<c[i])
		{
		max2=c[i];
		bh=i;
		}
	}
	b=max(b,xz(bh-1,m,1));
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
