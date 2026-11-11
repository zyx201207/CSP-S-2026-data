#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5; 
int c,n,m,d,q,w[MAXN],k[MAXN],xx,yy,dis[MAXN],id[MAXN];	//id[i]:i点到自己站台的时间 
int a[505][505],t[505][505],vis[MAXN],cnt,ans,db[MAXN];	//cnt:点数量 
int dd[5005][5005];
vector<pair<int,int> > ed[MAXN],zt[MAXN];	//db[i]:i代表那个地铁站 
struct node{
	int u,dis;
	bool operator > (const node& a) const{
		return dis>a.dis;
	}
};
priority_queue<node,vector<node>,greater<node> > qu;
void insert(int x,int y,int tm){
	ed[x].push_back(make_pair(y,tm));
	ed[y].push_back(make_pair(x,tm));
	dd[x][y]=dd[y][x]=tm;
}
void add(int x,int y,int tm)	//x站厅到y站走tm分钟 
{
	cnt++;
	db[cnt]=y;
	ed[x].push_back(make_pair(cnt,tm));
	ed[cnt].push_back(make_pair(x,tm));
	dd[x][cnt]=dd[cnt][x]=tm;
	for(int i=0;i<zt[y].size();i++)
		insert(cnt,zt[y][i].first,tm+zt[y][i].second);
	zt[y].push_back(make_pair(cnt,tm));
}
void dij(int st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(!qu.empty()) qu.pop();
	dis[st]=0;
	qu.push({st,0});
	while(!qu.empty()){
		int u=qu.top().u;
		qu.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i].first,ds=ed[u][i].second;
			if(dis[v]>dis[u]+ds){
				dis[v]=dis[u]+ds;
				qu.push({v,dis[v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(c>=8&&c<=11)
		memset(dd,0x3f,sizeof(dd));
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	cnt=n;					//有n个站 
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			add(i,a[i][j],t[i][j]);
			id[cnt]=t[i][j];
			if(j>1) insert(cnt,cnt-1,0);
		}
	}
	if(c>=8&&c<=11){
		for(int i=1;i<=cnt;i++)
			dd[i][i]=0;
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=i;j++)
				for(int k=i;k<=cnt;k++)
					dd[j][k]=dd[k][j]=min(dd[j][k],dd[j][i]+dd[i][k]);
	}
	while(q--){
		scanf("%d%d",&xx,&yy);
		ans=1e9;
		for(int i=0;i<zt[xx].size();i++){
			int qd=zt[xx][i].first;
			if(c<8||c>11) dij(qd);
			for(int j=0;j<zt[yy].size();j++){
				int zd=zt[yy][j].first;
				if(c>=8&&c<=11)
					ans=min(ans,w[db[qd]]+id[qd]+dd[qd][zd]+id[zd]+w[yy]);
				else ans=min(ans,w[db[qd]]+id[qd]+dis[zd]+id[zd]+w[yy]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
8 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
