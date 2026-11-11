#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10,INF=2147483647;
int c,n,m,d,q,ans;
struct node{
	int v,c,w;
};
struct _{
	int w;
	int t[N];
}a[M];
struct __{
	int l,r,q;
};
vector<node> edge[M];
int dis[M];
bool vis[M];
int lst[M];
bool ok=1;
void dij(int s,int e){
	for(int i=0;i<M;i++) dis[i]=INF,vis[i]=0;
	dis[s]=0;
	priority_queue<pair<int,int> > myq;
	myq.push({0,s});ans+=a[s].w;
	lst[s]=0;
	while(!myq.empty()){
		int u=myq.top().second;myq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		//cout<<":"<<u<<endl;
		for(auto x:edge[u]){
			int v=x.v,w=0,c=x.c;
			if(lst[u]!=c) w+=a[u].t[c]+a[v].t[c]/*,cout<<w<<endl*/;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				lst[v]=c;
				myq.push({-dis[v],v});
			}
		}
	}
	//for(int i=1;i<=m;i++){
	//	cout<<dis[i]<<" ";
	//}
	//cout<<endl;
	ans+=a[e].w;
	return ;
}
void dij2(int s,int e){
	for(int i=0;i<M;i++) dis[i]=INF,vis[i]=0;
	dis[s]=0;
	priority_queue<pair<int,int> > myq;
	myq.push({0,s});ans+=a[s].w;
	while(!myq.empty()){
		int u=myq.top().second;myq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto x:edge[u]){
			int v=x.v,w=x.w,c=x.c;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				myq.push({-dis[v],v});
			}
		}
	}
	ans+=a[e].w;
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i].w);
	}
	for(int i=1;i<=n;i++){
		int k,lstu,lstt;scanf("%d",&k);
		scanf("%d%d",&lstu,&lstt);
		for(int j=2;j<=k;j++){
			int x,y;scanf("%d%d",&x,&y);
			if(y!=lstt) ok=0;
			edge[lstu].push_back({x,i,lstt});
			edge[x].push_back({lstu,i,y});
			a[lstu].t[i]=lstt;
			lstu=x,lstt=y;
		}
		a[lstu].t[i]=lstt;
	}
	for(int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);
		ans=0;
		if(ok){
			dij2(x,y);
			cout<<ans+dis[y]<<endl;
			continue;
		}
		dij(x,y);
		cout<<ans+dis[y]<<endl;
	}
	return 0;
}
