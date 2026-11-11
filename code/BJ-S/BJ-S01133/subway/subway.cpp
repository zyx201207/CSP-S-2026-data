#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,n,m,d,q,w[500086];
long long ti[505][505];
struct line{
	int id;
	long long va;
};
vector<line> a[500086];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,v;
			cin>>u>>v;
			a[u].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) ti[i][j]=1e18+7;
	for(int i=1;i<=m;i++)
	{
		int k=a[i].size();
		for(int j=0;j<k;j++)
		{
			for(int k=0;k<j;k++)
			{
				line x=a[i][j],y=a[i][k];
				if(x.va+y.va<ti[x.id][y.id]) ti[x.id][y.id]=ti[y.id][x.id]=x.va+y.va;
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			cout<<ti[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(ti[i][k]+ti[k][j]<ti[i][j]) ti[i][j]=ti[j][i]=ti[i][k]+ti[k][j];
			}
		}
	}
	while(q--)
	{
		int x,y;
		long long ans=1e18+7;
		cin>>x>>y;
		for(auto f:a[x])
		{
			for(auto k:a[y])
			{
				 //cout<<f.va<<' '<<k.va<<' '<<ti[f.id][k.id]<<'\n';
				 ans=min(ans,f.va+k.va+ti[f.id][k.id]);
			 }
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
    return 0;
}
