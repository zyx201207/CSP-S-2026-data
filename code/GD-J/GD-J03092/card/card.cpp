#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[300000],sum[300000],vis[300000];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]!=0)
			{
				for(int k=vis[a[j]];k<j;k++) vis[a[k]]=0;
				vis[a[j]]=j;
			}
			else vis[a[j]]=j;
		}
		for(int j=1;j<=m;j++) 
		{
			if(vis[j]!=0) 
			{
				vis[j]=0;
				sum[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld",sum[i]);
		cout<<" ";
	}
	return 0;
}
