#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{int to,w,nxt;}a[3000005];
int c,n,m,d,Q;
int cnt,h[40005],wt[40005];
int dis[1005][40005],vis[40005],tot[5005];
void add(int u,int v,int w){
	a[++cnt].to=v;a[cnt].w=w;
	a[cnt].nxt=h[u];h[u]=cnt;
}
int gt(int x,int y){
	return (d+1)*(x-1)+y;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>wt[i];
		tot[i]=1;
	}
	int k,u,w;
	for(int i=1;i<=n;i++){
		cin>>k;int lst=0;
		for(int j=1;j<=k;j++){
			cin>>u>>w;
			tot[u]++;
			add(gt(u,1),gt(u,tot[u]),w);
			add(gt(u,tot[u]),gt(u,1),w);
			if(lst) add(gt(u,tot[u]),gt(lst,tot[lst]),0),
			add(gt(lst,tot[lst]),gt(u,tot[u]),0);
			lst=u;
		}
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=(d+1)*m;j++) vis[j]=0;
		while(!q.empty())q.pop();
		dis[i][gt(i,1)]=0;
		q.push({0,gt(i,1)});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int j=h[u];j;j=a[j].nxt){
				int v=a[j].to,w=a[j].w;
				if(dis[i][v]>dis[i][u]+w)
					dis[i][v]=dis[i][u]+w,
					q.push({dis[i][v],v});
			}
		}
	}
	int s,t;
	while(Q--){
		cin>>s>>t;
		cout<<dis[s][gt(t,1)]+wt[s]+wt[t]<<"\n";
	}
	return 0;
}
