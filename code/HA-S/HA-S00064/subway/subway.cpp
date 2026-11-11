#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int t[505],s[505][505];
struct node{
	int to,nxt,id;
}a[N];
int k,pre[N],dis[10005][505],vis[10005][505];
int c,n,m,d;
struct edge{
	int x,val,la;
	bool operator <(const edge &c) const{return c.val<val;}
};
priority_queue<edge> q;
void add(int u,int v,int d){
	a[++k]={v,pre[u],d};
	pre[u]=k;
}
int dijsta(int x,int y){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dis[j][i]=INT_MAX,vis[j][i]=0;
//	return 0;
	for(int i=1;i<=n;i++) dis[x][i]=t[x]+s[x][i],vis[x][i]=1,q.push({x,dis[x][i],i});
	while(!q.empty()){
		edge tp=q.top();
		q.pop();
		//cout<<tp.x<<" "<<tp.val<<"\n";
		vis[tp.x][tp.la]=1;
		for(int i=pre[tp.x];i!=0;i=a[i].nxt){
			int neva=dis[tp.x][tp.la];
			if(a[i].id!=tp.la && tp.la!=-1) neva+=s[tp.x][tp.la]+s[tp.x][a[i].id];
			//cout<<neva<<"-"<<dis[a[i].to][tp.la]<<"\n";
			//cout<<a[i].to<<":"<<neva<<" "<<a[i].id<<" "<<dis[a[i].to][a[i].id]<<"\n";
			if(neva<=dis[a[i].to][a[i].id] && !vis[a[i].to][a[i].id]) dis[a[i].to][a[i].id]=neva,q.push({a[i].to,dis[a[i].to][a[i].id],a[i].id});
		}
	}
	int mi=INT_MAX;
	for(int i=1;i<=n;i++) if(dis[y][i]!=INT_MAX)mi=min(mi,dis[y][i]+s[y][i]+t[y]);
	return mi;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int q;
	cin>>c>>n>>m>>d>>q;
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&t[i]);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1,las=0,u,v;j<=k;j++){
			cin>>u>>v;
			if(las!=0) add(las,u,i),add(u,las,i);
			s[u][i]=v;
			las=u;
		}
	}
	while(q--){
		int r_1,r_2;
		cin>>r_1>>r_2;
		cout<<dijsta(r_1,r_2)<<"\n";
	}
	return 0;
}

