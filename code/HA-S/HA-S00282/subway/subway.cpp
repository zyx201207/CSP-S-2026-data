#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll to,w;
	bool operator<(node y)const{
		return w>y.w;
	}
};
vector<node> g[40005];
priority_queue<node> pq;
ll c,n,m,d,q,w[20005],k[505],a[505][20005],t[505][20005],p[505][20005];
ll dis[40005],dis2[4005][4005],dis3[40005],cnt;
deque<node> dq;
bool f[40005],vis[40005];
inline void dijkstra(int s){
	memset(dis,0x3f,sizeof dis);
	memset(f,0,sizeof f);
	dis[s]=0; f[s]=1;
	while(pq.size()) pq.pop();
	pq.push({s,0});
	for(node t:g[s]){
		ll v=t.to,w=t.w;
		if(dis[s]+w<dis[v]){
			dis[v]=dis[s]+w;
			pq.push({v,dis[v]});
		}
	}
	for(int k=1;k<cnt;k++){
		node u=pq.top();
		pq.pop();
		while(dis[u.to]!=u.w){
			u=pq.top();
			pq.pop();
		}
		ll p=u.to;
		f[p]=1;
		for(node t:g[p]){
			ll v=t.to,w=t.w;
			if(dis[p]+w<dis[v]){
				dis[v]=dis[p]+w;
				pq.push({v,dis[v]});
			}
		}
	}
}
inline void dijkstra2(int s){
	memset(dis2[s],0x3f,sizeof dis2[s]);
	memset(f,0,sizeof f);
	dis2[s][s]=0; f[s]=1;
	while(pq.size()) pq.pop();
	pq.push({s,0});
	for(node t:g[s]){
		ll v=t.to,w=t.w;
		if(dis2[s][s]+w<dis2[s][v]){
			dis2[s][v]=dis2[s][s]+w;
			pq.push({v,dis2[s][v]});
		}
	}
	for(int k=1;k<cnt;k++){
		node u=pq.top();
		pq.pop();
		while(dis2[s][u.to]!=u.w){
			u=pq.top();
			pq.pop();
		}
		ll p=u.to;
		f[p]=1;
		for(node t:g[p]){
			ll v=t.to,w=t.w;
			if(dis2[s][p]+w<dis2[s][v]){
				dis2[s][v]=dis2[s][p]+w;
				pq.push({v,dis2[s][v]});
			}
		}
	}
}
inline void bfs(int s){
	memset(vis,0,sizeof(vis));
	memset(dis3,0x3f,sizeof(dis3));
	vis[s]=1;
	dq.push_back({s,0});
	dis3[s]=0;
	while(dq.size()){
		node p=dq.front();
		dq.pop_front();
		int u=p.to,w=p.w;
		dis3[u]=w;
		for(node to:g[u]){
			int v=to.to,k=to.w;
			if(vis[v]) continue;
			vis[v]=1;
			if(k==1) dq.push_back({v,w+k});
			else dq.push_front({v,w});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];cin>>t[i][j];
		}
	}
	if(c>=1&&c<=8){
		cnt=m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++){
				p[i][j]=++cnt;
				g[p[i][j]].push_back({a[i][j],t[i][j]});
				g[a[i][j]].push_back({p[i][j],t[i][j]});
				if(j>1){
					g[p[i][j]].push_back({p[i][j-1],0});
					g[p[i][j-1]].push_back({p[i][j],0});
				}
			}
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans=w[x]+w[y];
			dijkstra(x);
			cout<<ans+dis[y]<<'\n';
		}
	}
	else if(c>=9&&c<=11){
		cnt=m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++){
				p[i][j]=++cnt;
				g[p[i][j]].push_back({a[i][j],t[i][j]});
				g[a[i][j]].push_back({p[i][j],t[i][j]});
				if(j>1){
					g[p[i][j]].push_back({p[i][j-1],0});
					g[p[i][j-1]].push_back({p[i][j],0});
				}
			}
		for(int k=1;k<=cnt;k++) dijkstra2(k);
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans=w[x]+w[y];
			cout<<ans+dis2[x][y]<<'\n';
		}
	}
	else if(c>=12&&c<=19){
		cnt=m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++){
				p[i][j]=++cnt;
				g[p[i][j]].push_back({a[i][j],t[i][j]});
				g[a[i][j]].push_back({p[i][j],t[i][j]});
				if(j>1){
					g[p[i][j]].push_back({p[i][j-1],0});
					g[p[i][j-1]].push_back({p[i][j],0});
				}
			}
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans=w[x]+w[y];
			bfs(x);
			cout<<ans+dis3[y]<<'\n';
		}
	}
	return 0;
}
