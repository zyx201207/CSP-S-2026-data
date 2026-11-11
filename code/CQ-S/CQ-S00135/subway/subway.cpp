#include<bits/stdc++.h> // 未知 完蛋了我到底哪里错了啊 HELP ME ┭┮﹏┭┮ 
#define inf 0x3f3f3f3f
#define maxd 1000005
#define maxm 500005
#define maxn 505
using namespace std;
map<pair<int,int>,bool>vdis;
map<pair<int,int>,int>dis;
struct Edge{int v,w;};
vector<Edge>G[maxd];
void insert(int u,int v,int w)
{
	G[u].push_back(Edge{v,w});
	G[v].push_back(Edge{u,w});
	return;
}
bool vis[maxn];
int c,n,m,d;
int ni;
struct node
{
	int data;  // 值1 
	int data2; // 值2 
	int id;    // 分配到的位置 
	void build()
	{
		this->data=0;
		this->data2=0;
		this->fp();
	}
	int fp()
	{
		ni++;
		return id=ni;
	}
}w[maxm]; // id为站厅id 
vector<node>a[maxn]; // id为站台id 
queue<int>q;
void spfa(int s)
{
	while(!q.empty())
	{
		vis[q.front()]=false;
		q.pop();
	}
	dis[make_pair(s,s)]=0;
	vdis[make_pair(s,s)]=true;
	vis[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();vis[u]=false;q.pop();
		for(Edge edge:G[u])
		{
			int v=edge.v,w=edge.w;
			if(!vdis[make_pair(s,v)]||dis[make_pair(s,v)]>dis[make_pair(s,u)]+w)
			{
				dis[make_pair(s,v)]=dis[make_pair(s,u)]+w;
				vdis[make_pair(s,v)]=true;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	return;
}
void zdl()
{
	for(int i=1;i<=ni;i++)
		spfa(i);
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		w[i].build();
		cin>>w[i].data;
		w[i].fp();
	}
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,a_,t;j<=k;j++)
		{
			cin>>a_>>t;
			a[i].push_back(node{a_,t,0});
			a[i].back().fp();
			insert(a[i].back().id,w[i].id,t);
			if(j>1)
				insert(a[i][j-1].id,a[i][j-2].id,0);
		}
	}
	zdl();
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x].data+dis[make_pair(w[x].id,w[y].id)]+w[y].data<<endl;
	}
	return 0;
}
/*

17:12

玩了半天蜘蛛纸牌了，终于是想起来回来做题了:( 

还是没思路啊 

我难道要AFO了吗…… 

不！！！ 

我还不能AFO 

/(ㄒoㄒ)/~~ 

不要啊 

┭┮﹏┭┮ 

17:13 

完蛋了 

我要放弃了…… 

哎…… 

希望不会AFO吧…… 

祝我好运。 

17:14 

17:42

突然发现我又化身“老吃家”整整28分钟了……

就说怎么感觉那么大一包一会就没了……

－_－b 

话说剩下的时间我真的还能做出来吗？

想起了上次CSP-S 24分的经历……

不过这次好点，是60分（希望能有个3等奖吧 

17:44 

17:53 

感觉60分没跑了……

哎

*卒* 


18:16 

这下真卒了 

希望不会让我AFO…… 

/(ㄒoㄒ)/~~ 

*/
