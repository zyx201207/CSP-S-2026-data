#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 7;
const int lgN = 21;
vector<int> to[N];

bool safe[N];
int f[N][lgN],dfn[N],dep[N],tim,n,k;
vector<int> chsl;

void spread(int x,int dep,int mxdep){
	safe[x] = true;
	if(dep == mxdep)return;
	for(int v:to[x])
		if(!safe[v])spread(v,dep+1,mxdep);	
}

int gfa(int x,int lev){
	int now = x;
	for(int i=lgN;i>=0;i--){
		if((lev >> i)&1){
			now = f[now][i];
		}
	}
	return now;
}

void dfs(int x,int u,int fa){
	for(int v:to[u]){
		if(v != fa)dfs(x,v,u);
	}
	if(!safe[u]){
		int g = gfa(u,x);
		spread(g,0,x);chsl.push_back(g);
	}
}

void init(int x,int fa){
	f[x][0] = fa;dfn[x] = ++tim;dep[x] = dep[fa] + 1;
	for(int i=1;i<lgN;i++)
		f[x][i] = f[f[x][i-1]][i-1];
	for(int v:to[x]){
		if(v != fa)init(v,x);
	}
}

int lca(int u,int v){
	if(dep[u] < dep[v])swap(u,v);
	for(int i=lgN-1;i>=0;i--)
		if(dep[f[u][i]] >= dep[v])u = f[u][i];
	if(u == v)return u;
	for(int i=lgN-1;i>=0;i--)
		if(f[u][i] != f[v][i])u = f[u][i],v = f[v][i];
	return f[u][0];
}

void ctd(int u,int v){
	if(dep[u] > dep[v])swap(u,v);
	
}

bool cmp(int a,int b){
	return dfn[a] < dfn[b];
}

bool check(int x){
	//cout << "--------------" << x << "\n";
	chsl.clear();
	memset(safe,0,sizeof safe);
	dfs(x,1,0);
	return chsl.size() <= k;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int testid,_ = 1;cin >> testid >> _;
	while(_--){
		cin >> n >> k;
		for(int i=1;i<=n;i++)to[i].clear();
		
		for(int i=1;i<n;i++){
			int a,b;cin >> a >> b;
			to[a].push_back(b);
			to[b].push_back(a);
		}
		init(1,1);
		
		int l = 0,r = n,ans = n;
		while(l <= r){
			int mid = (l + r)/2;
			if(check(mid))ans = mid,r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << "\n";
	}
	return 0;
	//puts("I will earn 7 ticks!!!!!!!!!!!!!!!!!!!!!");
}


/*
Code by mid27_ (luogu)
Use ljy's 10 life to let this code get at least 30 scores!
RP++++++++++++++++++++++++++++++++++++++ 
*/
