//GZ-S00145 周小晰 贵阳一中 
#include<bits/stdc++.h>
using namespace std;
long long x[5005],y[5005],dis[5005],pre[5005],adj[5005][5005];
bool vis[5005];
long long n;
priority_queue <pair<long long,long long>> pq;
void dij(int s){
	dis[s]=0;
	pq.push({-dis[s],s});
	while(!pq.empty()){
		long long u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		bool flag = false;
		for(long long v=1;v<=n;v++){
			if(!vis[v]&&dis[v]>dis[u]+adj[u][v]){
				dis[v]=dis[u]+adj[u][v];
				pq.push({-dis[v],v});
				pre[v]=u;
			}
			else if(!flag&&!vis[v]&&dis[v]==dis[u]+adj[u][v]){
				pre[v] = -1;
				flag = true;
			}else if(flag&&!vis[v]&&dis[v]==dis[u]+adj[u][v]){
				pre[v] = 0;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof x);
		memset(dis,0,sizeof dis);
		memset(pre,0,sizeof pre);
		memset(adj,0,sizeof adj);
		memset(vis,false,sizeof vis);
		long long d,ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
			y[i] = x[i];
		}
		sort(y+1,y+n+1);
		long long t = 0 - y[1];
		for(long long i=1;i<=n;i++){
			x[i] += (t+1); 
		}
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				long long u=x[i];long long v=x[j];
				if(abs(u-v)<=d){
					adj[u][v]=abs(u-v);
				}
			}
		}
		dij(1);
		for(int i = 1;i <= n;i++){
			if(pre[i] == -1) ans++;
		}
		cout << ans <<endl;
	}
}
//40pts dij暴力+32pts特解=72pts 
//30min 暴力完成 
//dij大错特错 50min时 
