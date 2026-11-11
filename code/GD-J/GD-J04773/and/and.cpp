#include<bits/stdc++.h>
using namespace std;
int a[200005],ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f[n+5][m+5];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][1]=max(f[i-1][1],a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(j>i) continue;
			f[i][j]=max({f[i-1][j],f[i-1][j-1]&a[i]});
		}
	}
	cout<<f[n][m];
	return 0;
}

