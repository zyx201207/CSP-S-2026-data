#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
int c,t;
int n,d;
const int MAXN=2e6+5;
int x[MAXN];
vector<PII> g[MAXN];
int dis[MAXN];
int cnt[MAXN];
bool vis[MAXN];
void Dijkstra(int s){
	for(int i=1;i<=n;i++){
		dis[i]=INT_MAX;
	}
	dis[s]=0;
	cnt[s]=1;
	vis[s]=1;
	priority_queue<PII> pq;
	pq.push(PII(s,0));
	while(pq.size()){
		int u=pq.top().first,w=pq.top().second;
//		cout<<u<<"\n";
		pq.pop();
		for(PII x:g[u]){
			if(x.second>d) continue;
			int v=x.first,ww=x.second;
//			cout<<dis[u]<<" "<<ww<<" "<<dis[v]<<"\n";
			if(ww+dis[u]<dis[v]){
				dis[v]=ww+dis[u];
				pq.push(PII(v,ww+dis[u]));
				vis[v]=1;
			}
			if(ww+dis[u]==dis[v]){
				cnt[s]*=2;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		memset(cnt,0,sizeof(cnt));
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back(PII(i,j));
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			Dijkstra(i);
			memset(vis,0,sizeof(vis));
			if(cnt[i]==2){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
} 
