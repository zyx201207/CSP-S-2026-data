#include <bits/stdc++.h>
#define int long long
using namespace std;
int c1,q,d,n,m,c[512345],b[612][612];
vector <pair<int,int>> a[512345];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			int a1,t1;
			cin>>a1>>t1;
			a[a1].push_back({i,t1});
		}
	}
	memset(b,0x3f,sizeof b);
	for (int i=1;i<=n;i++)
	{
		b[i][i]=0;
	}
	for (int i=1;i<=m;i++)
	{
		for (auto it:a[i])
		{
			for (auto it1:a[i])
			{
				b[it.first][it1.first]=min(b[it.first][it1.first],it.second+it1.second);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (b[i][j]==b[0][0])
				continue;
			for (int k=1;k<=n;k++)
			{
				b[j][k]=min(b[j][k],b[j][i]+b[i][k]);
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int sum=b[0][0];
		for (auto it:a[x])
		{
			for (auto it1:a[y])
			{
				sum=min(sum,b[it.first][it1.first]+it.second+it1.second);
			}
		}
		cout<<sum+c[x]+c[y]<<endl;
	}
	return 0;
}
