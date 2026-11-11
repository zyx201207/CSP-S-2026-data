#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N=5e5+10,M=510;
int a[N],d[M][M];
vector<PII> e[N],z[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int ci,n,m,di,q;
	cin>>ci>>n>>m>>di>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		while(l--)
		{
			int v,w;
			cin>>v>>w;
			e[v].push_back({i,w}),z[i].push_back({v,w});
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)
		d[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(PII u:z[i])
			for(PII t:e[u.first])
			{
				int j=t.first,w=u.second+t.second;
				d[i][j]=min(d[i][j],w),d[j][i]=d[i][j];
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--)
	{
		int u,v,ans=1e18;
		cin>>u>>v;
		for(PII x:e[u])
			for(PII y:e[v])
			{
				int i=x.first,j=y.first;
				ans=min(ans,d[i][j]+x.second+y.second);
			}
		cout<<ans+a[u]+a[v]<<'\n';
	}
	return 0;
}
