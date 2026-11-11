#include <bits/stdc++.h>
using namespace std;
int n,m,ans=-1e9;
int a[2010];
int maxx=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int maxx1=-1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx1=max(a[i],maxx1);
	}
	if(m==n)
	{
		int jg1=a[1];
		for(int i=2;i<=n;i++)
		{
			jg1=jg1&a[i];
		}
		cout<<jg1;
		return 0;
	}
	if(m==1)
	{
		cout<<maxx1;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		
	cout<<maxx;
	return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				maxx=max(maxx,a[i]&a[j]&a[k]);
			}
		}
		
	cout<<maxx;
	return 0;
	}
	if(m==4){
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
				maxx=max(maxx,a[i]&a[j]&a[k]&a[l]);
			}
		}
		
	cout<<maxx;
	return 0;
	}
	if(m==5){
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
				for(int f=l+1;f<=n;f++)
				maxx=max(maxx,a[i]&a[j]&a[k]&a[l]&a[f]);
			}
		}
		
	cout<<maxx;
	return 0;
	}
	
	return 0;
	
}
