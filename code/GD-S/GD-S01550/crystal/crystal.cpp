#include<bits/stdc++.h>
using namespace std;
#define ing long long
int a[500005];
int c[5005][5005];
int f[5005];
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			c[i][j]=c[i][j-1]+(a[j]-a[j-1]);	
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i]+=c[j][i];
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(m>=f[i])
		{
			maxn=i;
			break;
		}
	}
	long long k=(a[1]+a[n])*((a[n]-a[1])/(a[2]-a[1])+1)/2;
	for(int i=n;i>=1;i--)
	{
		//cout<<k-a[i]<<" ";
		if((k-a[i])<=m)
		{
			maxn=max(maxn,i);
			//cout<<k<<" "<<i<<" "<<a[i]<<" ";
			break;
		}
		k-=a[i];  
	}
	cout<<maxn;
	return 0;
}
