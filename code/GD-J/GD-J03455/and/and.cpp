#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
		{
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
		return 0;
	} 
	if(m==n)
	{
		int sum=a[1]&a[2];
		for(int i=3;i<=n;i++)
		{
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;	
	}
	if(m==2)
	{
		int maxx=-1;
		int x;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				x=(a[i]&a[j]);
				maxx=max(maxx,x);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1)
	{
		int minx=10000;
		int k;
		for(int i=1;i<=n;i++)
		{
			if(minx>a[i])
			{
				k=i;
				minx=a[i];
			}
		}
		int sum=a[1]&a[2];
		for(int i=1;i<=n;i++)
		{
			if(i!=k){
				sum=(sum&a[i]);
			}
		}
		cout<<sum;	
	}
	return 0;
}
