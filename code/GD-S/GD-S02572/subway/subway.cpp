#include<bits/stdc++.h>
using namespace std;
int c,n,m,dd,qq;//测试点编号  线路数  站数  最多线路  计划出行数
int w[10005];//地铁口--站厅 
int t[505][10005];//线路  站点 
int d[10005];
bool vis[505][10005];
struct node1{
	int l;//时间 
	int dy; 
	int y;
	int x;
	bool operator<(const node1 k) const{
		return l>k.l;
	}
};
priority_queue<node1> q;
struct node{
	int x;
	int v;
};
vector<node> e[10005];
void dfs(int s){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	for(auto tmp:e[s])
	{
		int v=tmp.v;
		int x=tmp.x;
		d[v]=t[x][s];
		q.push({d[v],0,v,x});	
	}
	while(!q.empty())
	{
		auto cmp=q.top();
		q.pop();
		int sj=cmp.l;
		int u=cmp.y;
		int o=cmp.x;
		if(vis[o][u]||vis[u][o]) continue;
		vis[o][u]=1;
		vis[u][o]=1;
		for(auto tmp:e[u])
		{
			int x=tmp.x;
			int v=tmp.v;
			if(x==o)
			{
				if(u==s&&(sj+t[x][v]<d[v])){
					d[v]=sj+t[x][v];
					q.push({d[v],u,v,x});
				}
				else{
					if(d[v]>d[u]-t[x][u]+t[x][v]){				
						d[v]=d[u]-t[x][u]+t[x][v];
						q.push({d[v],u,v,x});
					}
				}
			}
			else{
				if(d[v]>sj+t[x][u]+t[x][v]&&u!=s){
					d[v]=sj+t[x][u]+t[x][v]; 
					q.push({d[v],u,v,x});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>dd>>qq;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int u,v;
		for(int j=1;j<=k;j++)
		{
			if(j==1) cin>>u;
			else{
				cin>>v;
				e[u].push_back({i,v});
				e[v].push_back({i,u});
				u=v;
			}
			cin>>t[i][u];
		}
	}
	for(int i=1;i<=qq;i++)
	{
		int x,y;
		cin>>x>>y;
		dfs(x);
		cout<<(d[y]+w[x]+w[y])<<"\n";
	}
	return 0;
}
