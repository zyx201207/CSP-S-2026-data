#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll N=5e5;
ll c,n,m,d,q,x,y,a,t,num,w[N],k[N],dis[N];
struct node{ll v,w;};
vector<node> e[N];

//k[i]表示第 i条线路经过的地铁站数
//a[i][j]表示第 i条线路经过的第 j个地铁站的编号 
//t[i][j]表示从地铁站 i的站厅走到 j号线对应的站台所需要的时间
//综合起来可以看作构建了一棵以一个代表 i号线的万能站台为根节点的树,多棵树共同连接成为一张图
//设第 i条线路的万能站台的编号为 m+i,第 i座地铁站的编号为 i,由此建图 

void dij()
{
	for(ll i=1;i<=m+n;i++) dis[i]=1e18;
	queue<ll> q;
	q.push(x);dis[x]=0;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		
		for(auto cur:e[u])
		{
			ll v=cur.v,w=cur.w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push(v);
			}
		}
	}
	return;
}

void solve()
{
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>k[i];
		for(ll j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
			num++;
		}
	}
	
	while(q--)
	{
		cin>>x>>y;
		dij();
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	
	return;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
