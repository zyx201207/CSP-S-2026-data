#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for (int i=(l);i<=(r);i++)
#define per(i,l,r) for (int i=(r);i>=(l);i--)

using namespace std;

const int N=20,inf=0x3f3f3f3f3f3f3f3f;

int n,m;
vector<int> e[N];
bool vis[N];

int bitcnt(int x){
	int res=0;
	while(x){
		x ^= x&-x;
		res++;
	}
	return res;
}
bool exist(int S,int x){
	return (S>>(x-1))&1;
}

void dfs(int u,int S){
//	printf("u:%lld\n",u);
	for(auto v:e[u]){
		if(vis[v] || !exist(S,v)) continue;
		vis[v]=1;
		dfs(v,S);
	}
}

int blkcnt(int S){
	memset(vis,0,sizeof(vis));
	int res=0;
	rep(i,1,n){
		if(vis[i] || !exist(S,i)) continue;
		vis[i]=1;
		dfs(i,S);
		res++;
	}
	return res;
}

int dis[N];
int bfs(int bg,int S){
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	q.emplace(bg),dis[bg]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		if(exist(S,u)) return dis[u];
		for(auto v:e[u]){
			if(dis[v]<=dis[u]+1) continue;
			dis[v]=dis[u]+1;
			q.emplace(v);
		}
	}
	return 0;
}

int getr(int S){
	int maxdis=0;
	rep(i,1,n){
		maxdis=max(maxdis,bfs(i,S));
	}
	return maxdis;
}

void solve(){
	cin>>n>>m;
//	printf("n:%lld m:%lld\n",n,m);
	rep(i,2,n){
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	
	int r=inf;
	rep(S,0,(1<<n)-1){
//		printf("r:%lld n:%lld\n",r,n);
		if(bitcnt(S)!=m) continue;
		if(blkcnt(S)>2) continue;
		r=min(r,getr(S));
		
	}
	
	cout<<r<<"\n";
	rep(i,1,n) e[i].clear();
}

signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--) solve();

	
	return 0;
}
