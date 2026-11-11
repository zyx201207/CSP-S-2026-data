#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int c,T,n,m,yes[N],dis[N],zo,cnt,xv[N],ans,ge;
priority_queue<pair<int,int> >q;
vector<int>b[N];
//int dfs(int x,int fa,int ha,int can,int k)
//{
//	if(f[x][ha][can][k])return f[x][ha][can][k];
//	for(int y:b[x])
//	{
//		if(y==fa)continue;
//		int zhi=0;
//	}
//}
void dfs(int x,int fa)
{
//	zo++;
//	cout<<x<<' '<<fa<<'\n';
//	if(zo>1000)return;
	if(yes[x]&&!yes[fa])ge++;
	if(yes[x])xv[++cnt]=x;
	for(int y:b[x])
	{
		if(y==fa)continue;
//		cout<<x<<" "<<y<<"??\n";
		dfs(y,x);
	}
}
void work()
{
	ge=cnt=0;
	dfs(1,0);
	if(ge>2)return;
	for(int i=1;i<=n;i++)dis[i]=n+1;
	sort(xv+1,xv+1+cnt);
//	cout<<xv[1]<<' '<<xv[2]<<"???\n";
//	if(xv[1]==1&&xv[2]==4)cout<<"??\n";
	for(int i=1;i<=cnt;i++)dis[xv[i]]=0,q.push(make_pair(0,xv[i]));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		for(int y:b[x])
		{
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
	int zhi=0;
	for(int i=1;i<=n;i++)zhi=max(zhi,dis[i]);
	ans=min(ans,zhi);
}
void ran(int now,int ge)
{
	if(ge==m)
	{
//		cout<<"???\n";
		work();
		return;
	}
	if(n-now+1+ge<m)return;
	yes[now]=1;ran(now+1,ge+1);
	yes[now]=0;ran(now+1,ge);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		ans=n+1;
		for(int i=1;i<=n;i++)b[i].clear();
		for(int u,v,i=1;i<n;i++)
		{
			cin>>u>>v;
			b[u].push_back(v);b[v].push_back(u);
		}
		ran(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
