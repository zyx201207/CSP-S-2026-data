#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e3+5;
ll f[N][N],inf;
int w[N],vis[N];
struct node{int v;ll w;};
bool operator <(node a,node b){return a.w>b.w;}
vector<node>e[N];
priority_queue<node>q;
void solve(int r){
	for(auto v:e[r])if(!f[v.v][r])q.push(v);
	while(!q.empty()){
		node v=q.top();
		q.pop();
		for(auto j:e[v.v]){
			if(!f[r][j.v]){
				f[r][j.v]=v.w+j.w;
				q.push({j.v,f[r][j.v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,T;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&T);
	for(int i=1; i<=m; i++)scanf("%d",&w[i]);
	for(int i=1; i<=n; i++){
		int k;
		scanf("%d",&k);
		for(int j=1,t,v; j<=k; j++){
			scanf("%d%d",&v,&t);
			e[v].push_back({i+m,t});
			e[i+m].push_back({v,t});
		}
	}
	for(int i=1; i<=m; i++)solve(i);
	while(T--){
		int x,y;scanf("%d%d",&x,&y);
		printf("%lld\n",f[x][y]+w[x]+w[y]);
	}
	return 0;
}
