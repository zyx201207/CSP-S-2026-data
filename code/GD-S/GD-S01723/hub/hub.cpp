#include<bits/stdc++.h>
#define ll long long
#define il inline
#define pll pair<ll, ll> 
using namespace std;

bool stMST;
ll c,t,n,k, ans;
vector<ll> g[1001000];
ll sz[1001000],f[1001000],d[1001000], son[1001000],top[1001000];

void df1(ll u, ll fa){
	f[u] = fa;
	d[u] = d[fa] + 1;
	sz[u] = 1;
	
	for(auto v : g[u]){
		if(v == fa) continue;
		df1(v,u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]){
			son[u] = v;
		}
	}
}
void df2(ll u, ll ftop){
	top[u] = ftop;
	
	if(son[u]) df2(son[u], ftop);
	
	for(auto v : g[u]){
		if(v == f[u] || v == son[u]) continue;
		df2(v,v);
	}
}
il ll LCA(ll x, ll y){
	while(top[x] != top[y]){
		if(d[top[x]] < d[top[y]]) swap(x,y);
		x = f[top[x]];
	}
	if(d[x] < d[y]) return x;
	return y;
}
il ll DIS(ll x, ll y){
	ll lca = LCA(x,y);
	return d[x]+d[y] - 2*d[lca];
}

ll fa[22] = {};
ll find(ll x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(ll x, ll y){
	ll fx = find(x), fy = find(y);
	fa[fx] = fy;
}

bool chk(ll S){
	for(int i=1;i<=n;++i){
		fa[i] = i;
	}
	
	set<ll> tmp;
	for(int k=0;k<n;++k){
		if((S>>k) & 1){
			tmp.insert(k+1);
		}
	}
	
	for(auto u : tmp){
		for(auto v : g[u]){
			if(tmp.count(v)){
				merge(u,v);
			}
		}
	}
	
	set<ll> cnt;
	for(auto u : tmp){
		cnt.insert(find(u));
	}
	
	if(cnt.size() > 2) return 0;
	return 1;
}

bool edMST;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

//	cout<<abs(&edMST-&stMST) / 1024.0 / 1024 <<" MB\n";
	
	cin>>c>>t;
	while(t--){
		ans = 1e18;
		
		cin>>n>>k;
		for(int u,v,i=1;i<=n-1;++i){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		df1(1,0);
		df2(1,1);
		
		if(n <= 20){
			for(int S=0;S<(1ll<<n);++S){
				if(__builtin_popcount(S) != k) continue;
				if(chk(S) == 0) continue;
				
				vector<ll> tmp;
				for(int k=0;k<n;++k){
					if((S>>k)&1){
						tmp.push_back(k+1);
					}
				}
				ll MA = 0;
				for(int u=1;u<=n;++u){
					ll d = 1e18;
					for(auto v : tmp){
						d = min(d, DIS(u,v));
					}
					MA = max(MA, d);
				}
				ans = min(ans, MA);
			}
			
			cout<<ans<<'\n';
		}else if(13 <= c && c <= 14){
			// 性质A
			// 就是在 m 的链上找两个连通块 
			ll m = n/2;
			if(k == 1){
				cout<<(m+2)/2<<'\n';
			}else{
				//((m+2)-k) / 4
				cout<<(m-k+7) / 4<<'\n';
			}
		}
		
		for(int i=1;i<=n;++i){
			g[i].clear();
			sz[i] = f[i] = d[i] = son[i] = top[i] = 0;
		}
	}
	
	
	
	
	return 0;
} 
