#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1],k[n+1],x[q+1],y[q+1];
	int z[m+1]={0},v[m+10]={0};
	int s[m+1][m+1]={0};
	int a[n+1][m+1],t[n+1][m+1];
	for(int i=1;i<=m;i++)  cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{ 
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i]-1;j++)
		{
			s[a[i][j]][a[i][j+1]]=t[i][j];
			z[a[i][j]]++;
			v[a[i][j]]=a[i][j+1];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		int ans=w[x[i]]+w[y[i]];int chushi=x[i];
		while(chushi!=y[i])
		{
			if(z[chushi]==1)
			{
				ans+=s[chushi][v[chushi]];
				chushi=v[chushi];
			}
		}
		cout<<ans;
	}
	return 0;
}
