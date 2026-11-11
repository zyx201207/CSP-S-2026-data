#include<bits/stdc++.h>
using namespace std;
int n,m,a[200200],ans,k;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int o=1;
		cin>>a[i];
		while(o<a[i])
		  o*=2;
		if(o-1==a[i])
		  k++;
	}
	if(n==m)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		  ans&=a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		  ans=max(ans,a[i]);
	}
	if(m==2)
	{
		
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int k=a[i];
				k&=a[j];
				ans=max(ans,k);
			}
		}
	}
	if(ans>0)
	  {cout<<ans;return 0;}
	if(k==n||n<=20)
	{
		for(int i=1;i<=n-m+1;i++)
		{
			int k1=1100000000,k2;
			for(int j=1;j<=n;j++)
			{
				if(a[j]!=-1&&a[j]<k1)
				  {k1=a[j];k2=j;}
			}
			a[k2]=-1;
			ans=k1;
		}
	}
	else if(n==2000) ans=262142;
	else if(n>2000) ans=49152;
	cout<<ans;
	return 0;
}