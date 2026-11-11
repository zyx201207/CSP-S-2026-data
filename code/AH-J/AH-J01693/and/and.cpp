#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int d[N][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int zd=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		zd=max(zd,a[i]);
	}
	if(m==1)
	{
		cout<<zd;
		return 0;
	}
	else if(m==2)
	{
		zd=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(i==j) continue;
				zd=max(zd,a[i]&a[j]);
			}
		}
		cout<<zd;
		return 0;
	}
	else if(m==n)
	{
		long long ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) d[i][0]=a[i];
	d[0][0]=a[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			d[i][j]=d[i-1][j];
			d[i][j]=max(d[i-1][j],(d[i-1][j-1]&a[i]));
		}
	}
	cout<<d[n][m];
	return 0;
} 
