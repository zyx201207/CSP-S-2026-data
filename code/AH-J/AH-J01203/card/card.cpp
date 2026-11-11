#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500003],sum[500003],sums[300003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int v=0;
		for(int j=0;j<n;j++)
		{
			if(a[i]==sum[j])
			{
				v++;
				for(int y=j;y<n;y++)
				{
					sum[y]=0;
				}
				break;
			}
		}
		if(v==0)
		{
			for(int j=0;j<n;j++)
			{
				if(sum[i]==0)
				{
					sum[i]=a[i];
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			for(int y=0;y<n;y++)
			{
				if(a[j]==sum[y])
				{
					sums[a[i]]++;
				}
			}
		}
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			cout<<sums[a[i]]<<' ';
		}
	}
	return 0;
}
