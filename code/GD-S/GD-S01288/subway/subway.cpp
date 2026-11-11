#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll w[500005];
ll k[105],a[105][500005],t[105][500005];
ll x,y,f[25][500005],vis[25][500005];
struct edge{
	ll e1,e2,wi;
};
struct node{
	ll X,Y;
	friend bool operator < (node a,node b){
		return f[a.X][a.Y]>f[b.X][b.Y];
	}
};
vector<edge>e[25][500005];
void dij(ll x,ll y){
	priority_queue<node>q;
	for(int i = 0;i <= d;i++){
		for(int j = 1;j <= m;j++){
			f[i][j]=1e17;
			vis[i][j]=0;
		}
	}
	f[0][x]=0;
	q.push({0,x});
	while(!q.empty()){
		node u=q.top();
		q.pop();
//		if(vis[u.X][u.Y])continue;
		vis[u.X][u.Y]=1;
		for(int i = 0;i < e[u.X][u.Y].size();i++){
			f[e[u.X][u.Y][i].e1][e[u.X][u.Y][i].e2]=min(f[e[u.X][u.Y][i].e1][e[u.X][u.Y][i].e2],f[u.X][u.Y]+e[u.X][u.Y][i].wi);
			if(vis[e[u.X][u.Y][i].e1][e[u.X][u.Y][i].e2]==0){
				q.push({e[u.X][u.Y][i].e1,e[u.X][u.Y][i].e2});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%lld",&k[i]);
		for(int j = 1;j <= k[i];j++){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
			e[i][a[i][j]].push_back({0,a[i][j],t[i][j]});
			e[0][a[i][j]].push_back({i,a[i][j],t[i][j]});
			if(j>1){
				e[i][a[i][j]].push_back({i,a[i][j-1],0});
				e[i][a[i][j-1]].push_back({i,a[i][j],0});
			}
		}
	}
	while(q--){
		scanf("%lld %lld",&x,&y);
		dij(x,y);
		printf("%lld\n",f[0][y]+w[x]+w[y]);
	}
	return 0;
} 
