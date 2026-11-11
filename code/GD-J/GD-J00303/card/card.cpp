#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,m,a[N],b[N],ans[N],c[N],bj,d[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d[a[i]]=i;
		if(a[i]<a[i-1]) bj=1;
	}
	if(bj==0)
	{
		for(int i=1;i<=m;i++)
			cout<<d[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]!=0) 
			{
				for(int k=b[a[j]];k<=j;k++)
					c[a[k]]=0;
			}
			b[a[j]]=j,c[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(c[j]==1) ans[j]++;
			c[j]=0,b[j]=0;
		}	
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
