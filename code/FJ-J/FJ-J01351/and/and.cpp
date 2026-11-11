#include <bits/stdc++.h>
using namespace std;
int f[4000][4000];
int n,m,a[20000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][1]=a[i];
	}
	int jjjj=a[1];
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			jjjj&=a[i];
		}
		cout<<jjjj;
		return 0;
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		int hj=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					hj=max(hj,a[i]&a[j]);
				}
			}
		}
		cout<<hj;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i][j],max(f[i-1][j],f[i-1][j-1]&a[i]));
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i][j],max(f[i-1][j],f[i+1][j-1]&a[i]));
		}
	}
	cout<<f[n][m];
}
