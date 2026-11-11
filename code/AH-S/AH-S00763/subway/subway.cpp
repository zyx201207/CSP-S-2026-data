#include<bits/stdc++.h>
#define MAXN 505
#define MAXM 500005
using namespace std;
int c,n,m,d,q,w[MAXM],k[MAXN];
vector<int> subway[MAXM];//每个点分别经过了多少个地铁
long long dist[MAXN][MAXN],ans[MAXM],val[MAXM][MAXN];
long long dist1[MAXN][MAXN];
int read(){
	int ans = 0;
	char ch=getchar();
	while(isdigit(ch)){
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}

vector<pair<int,int> >G[MAXN];
struct node{
	long long u,w;
	bool operator < (const node& rhs)const{return w > rhs.w;}
};
priority_queue<node> pq;
void dijkstra(int x){
	dist1[x][x] = 0;
	pq.push(node{x,0});
	while(pq.size()){
		node now = pq.top();pq.pop();
		int u = now.u, cost = now.w;
		for(auto nxt : G[u]){
			int v = nxt.first, w = nxt.second;
			if(dist1[x][v] > cost + w){
				dist1[x][v] = cost + w;
				pq.push(node{v,dist1[x][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof dist);
	memset(dist1,0x3f,sizeof dist1);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		dist[i][i] = 0;
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int sta;sta=read();
			val[sta][i]=read();
			subway[sta].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(subway[i].size() > 1){//这个位置是中转站
			for(int u : subway[i]){
				for(int v : subway[i]){
					dist[u][v] = min(dist[u][v],val[i][u] + val[i][v]);
					dist[v][u] = min(dist[v][u],val[i][u] + val[i][v]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i == j)continue;
			G[i].push_back(make_pair(j,dist[i][j]));
			G[j].push_back(make_pair(i,dist[j][i]));
		}
	if(n > 400)
		for(int i=1;i<=n;i++)dijkstra(i);
	else
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
	long long ans = LLONG_MAX;
	for(int i=1;i<=q;i++){
		ans = LLONG_MAX;
		int x,y;cin>>x>>y;
		for(int u : subway[x]){
			for(int v : subway[y]){
				long long sum = min(min(dist[u][v],dist[v][u]),min(dist1[u][v],dist1[v][u])) + val[x][u] +val[y][v];
				ans = min(ans,sum);
			}
		}
		ans += w[x] + w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
