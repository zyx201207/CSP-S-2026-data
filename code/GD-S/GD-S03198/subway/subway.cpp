#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,len[500005],k,a,t,dis[505][20005],vis[20005],u,v;
int head[600005],nxt[1100005],to[1100005],wei[1100005],cnt;
void add(int u,int v,int w){
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	wei[cnt]=w;
}
struct node{
	int id,dis;
	bool operator>(const node a)const{
		return dis>a.dis;
	}
};
priority_queue<node,vector<node>,greater<node>>pq;
void dij(int s){
	memset(dis[s],31,sizeof(dis[s]));
	memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	pq.push({s,dis[s][s]});
	while(!pq.empty()){
		node u=pq.top();
		pq.pop();
		if(vis[u.id])continue;
		vis[u.id]=1;
		for(int i=head[u.id];i;i=nxt[i]){
			int v=to[i];
			if(dis[s][v]>dis[s][u.id]+wei[i])dis[s][v]=dis[s][u.id]+wei[i],pq.push({v,dis[s][v]});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=n+1;i<=n+m;i++)
		cin>>len[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			add(a+n,i,t),add(i,a+n,t);
		}
	}
	if(c<=15){
		for(int i=1;i<=n;i++)
			dij(i);
		while(q--){
			cin>>u>>v;
			u+=n,v+=n;
			int ans=1e9+7;
			for(int i=1;i<=n;i++)
				ans=min(ans,dis[i][u]+dis[i][v]+len[u]+len[v]);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
