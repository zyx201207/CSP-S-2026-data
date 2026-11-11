#include<bits/stdc++.h>
using namespace std;
#define lep(i,a,b) for(int i = a,ed##i = b;i <= ed##i; ++i)
#define rep(i,a,b) for(int i = a,ed##i = b;i >= ed##i; --i)
int rd(){
	int res = 0,f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res * f;
}
const int N = 5e5 + 7,inf = 1e9 + 7;
int n,K;
vector<int> e[N];
int dep[N],fa[N],dis[N];
namespace Sub1{
	void dfs(int u){
		dep[u] = dep[fa[u]] + 1;
		for(int v : e[u]){
			if(v == fa[u]) continue;
			fa[v] = u;
			dfs(v);
		}
	}
	int LCA(int u,int v){
		if(dep[u] < dep[v]) swap(u,v);
		while(dep[u] > dep[v]) u = fa[u];
		if(u == v) return u;
		while(u != v){u = fa[u],v = fa[v];}
		return u;
	}
	bool typ[N],vis[N];
	void dfs1(int u,int pre){
		vis[u] = 1;
		for(int v : e[u]){
			if(v == pre || !typ[v]) continue;
			dfs1(v,u);
		}
	}
	bool check(int mask){
		lep(i,1,n) typ[i] = false,vis[i] = false;
		int cnt = 0;
		lep(i,1,n){if((mask>>(i-1))&1) typ[i] = 1,cnt++;}
		if(cnt > K) return false;
		cnt = 0;
		lep(i,1,n){
			if(typ[i] && !vis[i]) dfs1(i,0),++cnt;
		}
		if(cnt >= 3) return false;
//		lep(i,1,n) cerr << typ[i] << ' ';
//		cerr << mask << '\n';
		return 1;
	}
	void sol(){
		lep(i,1,n) e[i].clear();
		lep(i,1,n - 1){
			int u = rd(),v = rd();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1);
		int ans = inf;
		lep(mask,1,(1 << n) - 1){
			lep(i,1,n) dis[i] = inf;
			if(!check(mask)) continue;
//			cerr << "passed" << '\n';
			int res = 0;
			lep(i,1,n){
				if((mask>>(i-1))&1){
					lep(j,1,n){
						int lca = LCA(i,j);
//						cerr << "dis" << ' ' << i << ' ' << dep[i] + dep[j] - 2 * dep[lca] << '\n';
						dis[j] = min(dis[j],dep[i] + dep[j] - 2 * dep[lca]);
					}
				}
			}
//			lep(i,1,n) cerr << dis[i] << ' ';
//			cerr << '\n';
			lep(i,1,n) res = max(res,dis[i]);
			ans = min(ans,res);
		}
		cout << ans << '\n';
	}
}
void sol(){
	n = rd(),K = rd();
	Sub1::sol();return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int Case = rd(),Test = rd();
	while(Test --) sol();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
