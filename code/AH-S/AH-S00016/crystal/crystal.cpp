#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int a[500005];
long long b[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	
	
	
	for(int i=1;i<=n;i++)
	{
		b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	
	
	
	
	for(int i=1;i<=n;i++)
	{
		long long l=1,r=i,j=(l+r)/2;
		long long t=0;
		while(l<=r)
		{
			j=(l+r+1)/2;
			long long t2=((r-l+1)*a[i])-(b[r]-b[l-1]);
			if(t2<=m)
			{
				t=r-l+1;
				r=j-1;
				ans=max(ans,t);
			}
			else if(t2>m)
			{
				l=j+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
