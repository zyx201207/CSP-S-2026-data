#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define int long long
void fre()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
const int MAXN=2e6+10;
int c,t;
ll n,d,a[MAXN];
ll ver[MAXN],nex[MAXN],head[MAXN],edg[MAXN],tot;
void add(int x,int y,ll z)
{
	ver[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
	edg[tot]=z;
}
ll dis[MAXN],ans,cnt,minn;
bool vis[MAXN];
inline void dij(int s,int flag,int ed)
{

	for(int i=1;i<=n;i++)
	{
		dis[i]=4e18;
		vis[i]=0;
	}
	priority_queue<pair<ll,int> >q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		
		for(int i=head[u];i;i=nex[i])
		{
			int y=ver[i];
			ll z=edg[i];
			if(flag==1)
			{
				if(dis[u]+z==minn&&y==ed)
				{
					cnt++;
					
				}
			}
			if(dis[y]>dis[u]+z)
			{
				dis[y]=dis[u]+z;
				q.push({-dis[y],y});
			}
		}
	}
}
void fuck()
{
	for(int i=1;i<=tot;i++)
	{
		head[i]=0;
	}tot=0;
}
signed main()
{
	fre();
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					add(i,j,1);
					//cout<<i<<" "<<j<<endl;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				minn=4e18,cnt=0;
				dij(i,0,j);
				minn=dis[j];
				dij(i,1,j);//cout<<i<<" "<<j<<" "<<cnt<<" "<<dis[j]<<endl;
				if(cnt==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		fuck();
	}
	return 0;
}

