#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int f[1010][1010];
int b[1000010],s[1000010];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,q,n,k,t;
	cin>>c>>q>>n>>k>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=1e8;
		}
	}
	while(q--)
	{
		int m;
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>b[i]>>s[i];
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=i;j<=m;j++)
			{
				f[b[i]][b[j]]=min(f[b[i]][b[j]],s[i]+s[j]);
				f[b[j]][b[i]]=min(f[b[j]][b[i]],s[i]+s[j]);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][k]+f[k][j]<f[i][j])
				{
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		int sum=a[l]+a[r]+f[l][r];
		cout<<sum<<"\n";
	}
	return 0;
	
}

