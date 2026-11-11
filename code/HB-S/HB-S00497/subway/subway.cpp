#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
const int maxm=5e5+5,maxn=505;
int c,n,m,d,q,w[maxm],k[maxn],cnt[maxm];
ll dis[maxn][maxn],ans;
pii g[maxm][21];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n)
	{
		cin>>k[i];
		rep(j,1,k[i])
		{
			int x,y;
			cin>>x>>y;
			g[x][++cnt[x]]={i,y};
		}
	}
	memset(dis,0x3f,sizeof(dis));
	rep(i,1,n)dis[i][i]=0;
	rep(i,1,m)
		rep(j,1,cnt[i])
			rep(k,j+1,cnt[i])
			{
				ll x=g[i][j].fi,vx=g[i][j].se,y=g[i][k].fi,vy=g[i][k].se;
				dis[x][y]=min(dis[x][y],vx+vy);dis[y][x]=dis[x][y];
			}
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int s,t;
		cin>>s>>t;
		ans=1e18;
		rep(i,1,cnt[s])
			rep(j,1,cnt[t])
			{
				ll x=g[s][i].fi,vx=g[s][i].se,y=g[t][j].fi,vy=g[t][j].se;
				ans=min(ans,w[s]+w[t]+vx+vy+dis[x][y]);
			}
		cout<<ans<<'\n';
	}
	return 0;
}
