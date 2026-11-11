#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=2e17;
int c,n,m,d,T;
int w[505];
struct edge{
	int y;
	ll t;
};
vector<edge>v[600005];
ll dis[600005];
map<int,ll>dp[600005];
bool vis[600005];
void dijkstra(int x){
	for(int i=1;i<=n+m;i++)dis[i]=INF;
	dis[x]=0;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<v[x].size();i++){
			int y=v[x][i].y;
			ll t=v[x][i].t;
			if(dis[y]>dis[x]+t){
				dis[y]=dis[x]+t;
				q.push(y);
			}
		}
	}
	for(int i=1;i<=n+m;i++)dp[x][i]=dis[i];
	vis[x]=1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&T);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d ",&k);
		for(int j=1;j<=k;j++){
			int y;
			ll s;
			scanf("%d %lld",&y,&s);
			v[m+i].push_back({y,s});
			v[y].push_back({m+i,s});
		}
	}
	for(int i=1;i<=T;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(!vis[x])dijkstra(x);
		printf("%lld\n",dp[x][y]+w[x]+w[y]);
	}
	return 0;
}
