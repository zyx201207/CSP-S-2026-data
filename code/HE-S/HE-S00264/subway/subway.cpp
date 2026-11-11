#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500010];
int cnt,pre[500010];
int x,y;
int ans = 0;
int dian[500010]; 
struct Pos{
	int a,t;
}p[500010];
struct Edge{
	int from,to,next,val;
}edge[2*500010];
void addedge(int u,int v,int val){
	cnt++;
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt].next = pre[u];
	edge[cnt].val = val;
	pre[u] = cnt;
}
void dfs(int u,int fa){
	for(int j = pre[u];j;j = edge[j].next){
		int to = edge[j].to;
		int val = edge[j].val;
		if(to == y) break;
		if(to == fa) continue;
		dfs(to,u);
		ans += val;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin >> k;
		while(k--){
			cin >> p[i*2+1].a >> p[i+2+1].t;
			addedge(p[i*2].a,p[i*2+1].a,p[i*2].t+p[i*2+1].t);
		}
	}
	while(q--){
		cin >> x >> y;
		dfs(x,0);
		cout << w[x] + w[y] + p[x].t + p[y].t;
	}
	return 0;
}
