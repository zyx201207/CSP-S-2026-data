#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],f[500005],v[500005],maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1;
	}
	for(int i=2;i<=n;i++)
	{
		v[i]=a[i]-a[i-1]+v[i-1];
		
	}
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++)
	{
		int x=m;
		for(int j=i-1;j>0;j--)
		{
			if(v[i]-v[j]<=x)
			{
				x-=(v[i]-v[j]);
				f[i]++;
			}
			else break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,f[i]);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);	
} 
