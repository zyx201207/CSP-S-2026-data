#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN=510,MAXM=5e5+10;
int c,n,m,d,q,w[MAXM],a[MAXN][25],dis[MAXN][MAXN],k[MAXN],t[MAXN][25];
vector<pair<int,int> > z[MAXM];
signed main(  )
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j],z[a[i][j]].push_back({i,t[i][j]});
	}
	for(int i=1;i<=m;i++)
		for(auto &j:z[i])
			for(auto &kk:z[i])
			{
				if(j.fi==kk.fi) continue;
				dis[j.fi][kk.fi]=dis[kk.fi][j.fi]=min(dis[j.fi][kk.fi],j.se+kk.se);
			}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int kk=1;kk<=n;kk++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int res=1e18;
		for(auto &i:z[x])
			for(auto &j:z[y])
			{
				res=min(dis[i.fi][j.fi]+i.se+j.se,res);
			}
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}
