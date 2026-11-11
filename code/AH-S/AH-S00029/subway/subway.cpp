#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int d,v;
};
const int N=1010;
vector<Node>e[N];
int c,n,m,d,q,a[N],dis[N][N];
void dij(int x){
	dis[x][x]=0;
	priority_queue<pair<int,int>>p;
	p.push({0,x});
	while(!p.empty()){
		int u=p.top().second;
		for(auto v:e[u]){
			if(dis[v.v][x]==-1||dis[v.v][x]>v.d+p.top().first){
				dis[v.v][x]=v.d+p.top().first;
				p.push({dis[v.v][x],v.v});
			}
		}
		p.pop();
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(7<=c&&c<=11){
		memset(dis,-1,sizeof dis);
		for(int j=1;j<=m;j++){
			scanf("%lld",&a[j]);
		}
		for(int i=1;i<=n;i++){
			int x,l1,r1,l2,r2;
			scanf("%lld",&x);
			if(x==1) scanf("%lld%lld",&l1,&r1);
			else{
				scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
				e[l1].push_back({r1+r2,l2});
				e[l2].push_back({r1+r2,l1});
			}
		}
		for(int i=1;i<=n;i++) dij(i);
		for(int i=1;i<=q;i++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",dis[x][y]+a[x]+a[y]);
		}
	}
	return 0;
}
