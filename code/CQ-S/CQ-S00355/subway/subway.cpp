#include<bits/stdc++.h>
using namespace std;
const int N=500+5,M=1e5+5,B=2e3+5;
const long long INF=1e18;
struct czc
{
	int to,val;
};
struct hzl
{
	int u,v;
};
struct pyb
{
	int id;
	long long d;
	bool operator < (const pyb &other) const
	{
		return d>other.d;
	}
};
hzl ask[M];
int c,n,m,d,q,w[M],vis[N+M];
vector<long long> dis[B];
vector<int> f;
vector<czc> edge[N+M];
void dij(int s,int o)
{
	priority_queue<pyb> q;
	for(int i=1;i<=n+m;i++) dis[o][i]=INF,vis[i]=0;
	q.push({s,0}),dis[o][s]=0;
	while(!q.empty())
	{
		pyb first=q.top();
		q.pop();
		if(vis[first.id]) continue ;
		vis[first.id]=1;
		int len=edge[first.id].size();
		for(int i=0;i<len;i++)
		{
			int to=edge[first.id][i].to,val=edge[first.id][i].val;
			if(dis[o][to]>dis[o][first.id]+val)
			{
				dis[o][to]=dis[o][first.id]+val;
				q.push({to,dis[o][to]});
			}
		}
	}
}
void init()
{
	int up=((12<=c && c<=15)?q:m);
	for(int i=1;i<=up;i++) dis[i].resize(n+m+5);
	for(int i=1;i<=up;i++)
	{
		int now=((12<=c && c<=15)?f[i-1]:i);
		dij(now,i);
	}
}
void solve()
{
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	
	for(int i=1;i<=n;i++)
	{
		int total;
		scanf("%d",&total);
		for(int j=1;j<=total;j++)
		{
			int u,val;
			scanf("%d%d",&u,&val);
			edge[m+i].push_back({u,val}),edge[u].push_back({m+i,val});
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&ask[i].u,&ask[i].v);
		if(12<=c && c<=15) f.push_back(ask[i].u); 
	}
	init();
	for(int i=1;i<=q;i++)
	{
		int now=((12<=c && c<=15)?i:ask[i].u);
		printf("%lld\n",dis[now][ask[i].v]+w[ask[i].u]+w[ask[i].v]);
	}
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();	
	
	return 0;
}
/*
我是打不出来正解了，只能在基础上做暴力了
已知信息：二分图+左边n个点，右边m个点，边数=m*d
第一个点：左边3个，右边m个，边数10
先建边，q小等于10，直接跑dfs找最小
第二个点 ，左边50，右边 300，边数300
还是dfs
第三个点，200+400+400
还是dfs
第四个点 500+1000+1000
dfs
第5、6、7、8、9、10个点 500+2e4+2e4
dfs
？
dfs复杂度：（点数+边数）*点数
1~15都好像可以过 
*/
