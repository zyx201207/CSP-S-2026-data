#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int s,t;
};
vector<node> acc[500005];
int c,n,m,d,q,k,tot[505][505],w[500005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) tot[i][j]=1e15;
	for(int i=1;i<=n;i++) tot[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			acc[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<acc[i].size();j++)
			for(int l=0;l<j;l++)
			{
				tot[acc[i][l].s][acc[i][j].s]=min(tot[acc[i][l].s][acc[i][j].s],acc[i][l].t+acc[i][j].t);
				tot[acc[i][j].s][acc[i][l].s]=min(tot[acc[i][j].s][acc[i][l].s],acc[i][l].t+acc[i][j].t);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				tot[i][j]=min(tot[i][j],tot[i][k]+tot[k][j]);
	while(q--)
	{
		int x,y,ans=1e15;
		cin>>x>>y;
		for(int i=0;i<acc[x].size();i++)
			for(int j=0;j<acc[y].size();j++)
				ans=min(ans,w[x]+w[y]+acc[x][i].t+acc[y][j].t+tot[acc[x][i].s][acc[y][j].s]);
		cout<<ans<<"\n";
	}
	return 0;
}
