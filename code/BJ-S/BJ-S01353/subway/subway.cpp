#include<bits/stdc++.h>
using namespace std;
#define int LL
typedef long long LL;
const int N=3200000,M=500010;//N为边数上限400*400*200
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
int c,n,m,x,y,d,q,k,tot;
int w[M],a[M],t[M];
int to[2*N],len[2*N],nxt[2*N],wz[2*N],head[M],vis[M],now[M];//wz存的是在第几条线
int dis[1010][1010];
void add(int u,int v,int w,int b){
	++tot;
	to[tot]=v;
	len[tot]=w;
	wz[tot]=b;
	nxt[tot]=head[u];
	head[u]=tot;
	return;
}
void bfs(int s){
	vis[s]=1;
	dis[s][s]=0;
	que.push({s,w[s]});
	while(!que.empty()){
		int p=que.top().first;
		que.pop();
		vis[p]=1;
		for(int i=head[p];i!=0;i=nxt[i]){
			int v=to[i];
			if(vis[v]==0){
				if(p==s){
					now[v]=wz[i];
					dis[s][v]=dis[s][p]+len[i]+len[i^1];
					que.push({v,dis[s][v]});
				}else{//一个地铁站被多条线路经过 如何判定是否换乘?
					if(now[p]!=wz[i]){
						if(dis[s][v]>dis[s][p]+len[i]+len[i^1]){
							dis[s][v]=dis[s][p]+len[i]+len[i^1];
							que.push({v,dis[s][v]});
						}
					}else{
						if(dis[s][v]>dis[s][p]+len[i]){
							dis[s][v]=dis[s][p]+len[i];
							que.push({v,dis[s][v]});
						}
					}
				}			
			}
		}
	}
	return;
}
signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	tot=1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int o=1;o<=n;o++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				if(i==j){
					continue;
				}
				add(a[i],a[j],t[j],o);
				add(a[j],a[i],t[i],o);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		bfs(i);
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<"\n";
	}
	return 0;
}