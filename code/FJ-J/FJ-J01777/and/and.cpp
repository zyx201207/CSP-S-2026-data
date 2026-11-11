#include <bits/stdc++.h>
using namespace std;
const int M=200005;
int nn[M];
int maxn[2005][M];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&nn[i]);
	}
	for(int i=1;i<=m;i++)
	{
		maxn[i][1]=nn[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<=m;j++)
		{
			maxn[i][j]=maxn[i][j-1]&nn[i];
		}
	}
	for(int i=m;i<=n;i++)
	{
		for(int j=m;j<=n;j++)
		{
			
			maxn[i][j]=max(maxn[i-1][j]&nn[i],maxn[i][j-1]);
		}
	}
	cout<<maxn[n][n];
	return 0;
}
