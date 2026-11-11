#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
struct node{int v,w;};
struct cmp{bool operator()(node x,node y)const{return x.w>y.w;}};
vector<node> G[2000005];
int dist[2000005];
int new_node=0;
int ans[100005];
bool vis[2000005];
vector<node> qu[500005];
struct Query{int l,r,id;}num[100005];
bool cmpq(Query x,Query y){return x.l<y.l;}
priority_queue<node,vector<node>,cmp> Q;
void dij(int st)
{
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	Q.push((node){st,0});dist[st]=0;
	while(Q.size())
	{
		node t=Q.top();Q.pop();
		if(vis[t.v])continue;
		vis[t.v]=1;
		for(node u:G[t.v])
		{
			if(dist[u.v]>dist[t.v]+u.w)
			{
				dist[u.v]=dist[t.v]+u.w;
				Q.push((node){u.v,dist[u.v]});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;new_node=m*2;
	for(int i=1;i<=m;i++)
	{
		int w;cin>>w;
//		cout<<i<<" <--> "<<i+m<<"\n";
		G[i].push_back((node){i+m,w});
		G[i+m].push_back((node){i,w});
	}
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,nowu,t;cin>>a>>t;
			nowu=++new_node;
//			cout<<nowu<<" <--> "<<a+m<<"\n";
			G[nowu].push_back((node){a+m,t});
			G[a+m].push_back((node){nowu,t});
			if(j!=1)
			{
//				cout<<nowu<<" <--> "<<nowu-1<<"\n";
				G[nowu].push_back((node){nowu-1,0});
				G[nowu-1].push_back((node){nowu,0});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>num[i].l>>num[i].r;num[i].id=i;
		if(num[i].l>num[i].r)swap(num[i].l,num[i].r);
	}sort(num+1,num+q+1,cmpq);
	for(int i=1;i<=q;i++)
	qu[num[i].l].push_back((node){num[i].r,num[i].id});
	for(int i=1;i<=m;i++)
	{
		if(qu[i].size()==0)continue;
		dij(i);/*cout<<i<<"\n";
		for(int i=1;i<=m;i++)cout<<dist[i]<<" ";
		cout<<"\n";
		for(int j=0;j<qu[i].size();j++)
		cout<<qu[i][j].v<<" "<<dist[qu[i][j].v]<<"\n";*/
		for(int j=0;j<qu[i].size();j++)ans[qu[i][j].w]=dist[qu[i][j].v];
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}
