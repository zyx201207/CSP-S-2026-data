#include<bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int N = 5e5+7;

int c,n,m,d,q,fa[N],cnt,anc[N][27];

ll w[N],k[N],pre[N],depth[N];

unordered_map<int,ll> t[507];

struct node{
	int to,line;
};

struct road{
	int u,v,line;
	ll w;
}tr[N];

int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

vector<node> g[N];

void kru(){
	int res = 0;
	for(int i = 1;i<=cnt;i++){
		int u = tr[i].u,v = tr[i].v;
		ll w = tr[i].w;
		int fu = find(u),fv = find(v);
		if(fu == fv) continue;
		fa[fu] = fv;
		g[u].push_back({v,tr[i].line});
		g[v].push_back({u,tr[i].line});
		res ++;
		if(res == m-1) break;
	}
}

void dfs(int u,int fa,int l){
	pre[u] += t[l][u];
	depth[u] = depth[fa] + 1;
	anc[u][0] = fa;
	for(int i = 1;i<27;i++){
		anc[u][i] = anc[anc[u][i-1]][i-1];
	}
	for(const auto&it:g[u]){
		int to = it.to,line = it.line;
		if(to == fa) continue;
		if(l == line) pre[to] += pre[u] - t[l][u];
		if(l != line) pre[to] += pre[u] + t[line][u];
		dfs(to,u,line);
	}
}

pair<int,int> lca(int x,int y){
	if(depth[x] < depth[y]) swap(x,y);
	for(int i = 26;i>=0;i--){
		if(depth[anc[x][i]] >= depth[y]) x = anc[x][i];
	}
	if(x == y) return {x,y};
	for(int i = 26;i>=0;i--){
		if(anc[x][i] != anc[y][i]){
			x = anc[x][i],y = anc[y][i];
		}
	}
	return {x,y};
}

int main(){freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
//	freopen("input.txt","r",stdin);freopen("ans.txt","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
		fa[i] = i;
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		int last = 0;
		for(int j = 1;j<=k;j++){
			int u;
			ll v;
			cin>>u>>v;
			t[i][u] = v;
			if(j != 1) tr[++cnt] = {last,u,i,t[i][u]+t[i][last]};
			last = u;
		}
	}
	sort(tr+1,tr+1+cnt,[](road a,road b){
		return a.w < b.w;
	});
	kru();
	dfs(1,-1,0);
	while(q--){
		int s,e;
		cin>>s>>e;
		pair<int,int> mid = lca(s,e);
		int x = mid.first,y = mid.second,l1,l2,ft = anc[x][0];
		if(x == y){
			l1 = l2 = 1;
			ft = x;
		}else{	
			for(const auto &it:g[x]){
				if(it.to == ft){
					l1 = it.line;
					break;
				}
			}
			for(const auto &it:g[y]){
				if(it.to == ft){
					l2 = it.line;
					break;
				}
			}
		}
		cout<<w[s]+w[e]+pre[s]+pre[e]-2*pre[ft] + (l1 != l2&&ft != 1)*t[l1][ft]<<'\n';
	}
	return 0;
}
