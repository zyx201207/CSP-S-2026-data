#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200002],ans;
long long f[200002][200002],f1[200002][200002][200002];
bool cut(long long a,long long b)
{
	return a>=b;
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cut);
	for(int i=1;i<=200002;i++)
	{
		for(int j=1;j<=200002;j++)
		{
			f[i][j]=i&j;
			for(int k=1;k<=200002;k++)
			{
				f1[i][j][k]=f[i][j]&k;
			}
		}
	}
	if (m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				ans=max(ans,f[a[i]][a[i+1]]);
		}
	}
	if (m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					ans=max(ans,f1[a[i]][a[j]][a[k]]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}