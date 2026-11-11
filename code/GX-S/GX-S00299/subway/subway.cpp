#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+510,M=5e5+510,MAXN=0x7fffffff;
struct edge{
	ll to,pre,w;
}b[M*2];
ll head[N],cnt;
ll c,n,m,d,que,st[N];
ll dis[N],vis[N];
struct node{
	ll id,val;
	bool operator <(const node &Y)const{
		return val>Y.val;
	}
};

priority_queue<node> q;

void add(int x,int y,int z)
{
	cnt++;b[cnt].to=y;b[cnt].w=z;b[cnt].pre=head[x];head[x]=cnt;
}
void dij(ll s)
{
	q.push({s,0});
	for(int i=1;i<=n+m;i++)
	{
		dis[i]=MAXN;
	}
	dis[s]=0;
	while(!q.empty())
	{
		node p=q.top();q.pop();
		if(vis[p.id])
			continue;
		vis[p.id]=1;
		for(int i=head[p.id];i;i=b[i].pre)
		{
			int y=b[i].to;
			if(dis[y]>dis[p.id]+b[i].w)
			{
				dis[y]=dis[p.id]+b[i].w;
				q.push({y,dis[y]});
			}
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>que;
	for(int i=1;i<=m;i++)
	{
		cin>>st[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			ll y,z;
			cin>>y>>z;
			add(i,y+n,z);
			add(y+n,i,z);
		}
	}
	for(int i=1;i<=que;i++)
	{
		ll x,y;
		cin>>x>>y;
		dij(x+n);
		cout<<st[x]+st[y]+dis[y+n];
		//for(int j=n+1;j<=m+n;j++)
			//cout<<dis[j]<<" ";
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		cout<<"\n";
	}
	return 0;
}
/**/
