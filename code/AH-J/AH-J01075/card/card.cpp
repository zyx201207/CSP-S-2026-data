#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001][2],c[300001],ans[300001],k[300001],flag[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	bool f1=1;
	for(int i=2;i<=n;i++)
	  if(a[i]<a[i-1])f1=0;
	if(m==2)
	{
		for(int i=1;i<=2;i++)
		{
			if(a[n]==i)cout<<n<<' ';
			else
			{
				int ct=0;
				for(int i=1;i<n;i++)
				  if(a[i]==i)ct++;
				cout<<ct<<' ';
			}
		}
	}
	else if(f1==1)
	{
		for(int i=1;i<=n;i++)
		  b[a[i]][1]=i;
		for(int i=1;i<=m;i++)
		  cout<<b[i][1]<<' ';
	}
	else
	{
		for(int i=1;i<=n;i++)
		  c[a[i]]++;
		for(int i=1;i<=m;i++)
		{
			if(a[n]==i)cout<<n<<' ';
			else cout<<c[i]<<' ';
		}
	}
	return 0;
}
