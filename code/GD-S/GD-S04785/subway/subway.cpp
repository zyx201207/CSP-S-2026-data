#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
int he[610],to[810],ne[810],we[810],idx;
void add(int a,int b,int c){
	ne[++idx]=he[a];
	he[a]=idx;
	to[idx]=b;
	we[idx]=c;
}

int kou[410];
int c,n,m,emp,q,k,a,t,x,y;

int d[610];
bool vis[610];
void dijk(int s){
	memset(d,INF,sizeof d);
	memset(vis,0,sizeof vis);
	d[s]=0;
	priority_queue<pair<int,int>> q;
	q.push({0,s});
	int u;
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		if(vis[u])	continue;
		vis[u]=1;
		for(int i=he[u],v,w;i;i=ne[i]){
			v=to[i],w=we[i];
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				if(vis[v])	continue;
				q.push({-d[v],v});
			}
		}
	}
}

int solve(int x,int y){
	dijk(x);
	return kou[x]+kou[y]+d[y];
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> emp >> q;
	for(int i=1;i<=m;i++){
		cin >> kou[i];
	}
	
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a >> t;
			add(m+i,a,t);
			add(a,m+i,t);
		}
	}
	
	for(int i=1;i<=q;i++){
		cin >> x >> y;
		cout << solve(x,y) << '\n';
	}
	
	return 0;
}
