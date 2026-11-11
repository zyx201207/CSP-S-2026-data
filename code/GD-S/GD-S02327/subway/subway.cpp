#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int asdfghjkl,n,m,d,q;
int a[505][505];
int t[500005];
vector<pii> g[500005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>asdfghjkl>>n>>m>>d>>q;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<=n;i++)
	{
		a[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			for(pii v:g[x])
			{
				a[i][v.fi]=min(a[i][v.fi],y+v.se);
				a[v.fi][i]=a[i][v.fi];
			}
			g[x].push_back({i,y});
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e9;
		for(pii i:g[x])
		{
			for(pii j:g[y])
			{
				ans=min(ans,a[i.fi][j.fi]+i.se+j.se);
			}
		}
		cout<<ans+t[x]+t[y]<<"\n";
	}
	return 0;
}
