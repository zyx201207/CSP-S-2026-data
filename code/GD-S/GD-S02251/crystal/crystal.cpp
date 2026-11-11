#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n];
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]>a[i+1])
			{
				int l=a[i];
				a[i]=a[i+1];
				a[i+1]=l;
			}
		}
	}
	int b=round(n/2);
	int c=m;
	for(int i=0;i<n;i++)
	{
		if(a[b]-a[b-1]<c)
		{
			c-=(a[b]-a[b-i]);
			a[b-i]=a[b];
			if(c<0)
			{
				c+=(a[b]-a[b-i]);
				continue;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]=a[i-1])
		{
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
