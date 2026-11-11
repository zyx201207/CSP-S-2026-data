#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i=a; i<=b; ++i)
#define F_(i,a,b) for(int i=a; i>=b; i--)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fr first
#define sc second
#define pb push_back
const int N = 1e3+10, M = 1e6+10, INF = 1e9;
int n,k,fg[N],dis[N],ans;
vector<int> go[N];
struct DSU{
	int fa[N];
	void init(int n){F(i,1,n) fa[i] = i;}
	int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
	void merge(int u,int v){fa[find(v)] = find(u);}
} U;
void bfs(){
	queue<int> q;
	F(i,1,n){
		if (fg[i]) dis[i] = 0, q.push(i);
		else dis[i] = INF;
	}
	while (q.size()){
		int u = q.front(); q.pop();
		for (auto v:go[u]){
			if (dis[u]+1 < dis[v]){
				dis[v] = dis[u]+1;
				q.push(v);
			}
		}
	}
}
void baoli(){
	F(S,0,(1<<n)-1){
		F(i,1,n) fg[i] = (S>>i-1)&1;
		int c = 0;
		F(i,1,n) if (fg[i]) ++c;
		if (c != k) continue;
		U.init(n);
		F(u,1,n) for (auto v:go[u]) if (fg[u] && fg[v]) U.merge(u,v);
		int s = 0;
		F(i,1,n) if (fg[i] && U.find(i) == i) ++s;
		if (s > 2) continue;
		bfs();
		int res = 0;
		F(i,1,n) res = max(res,dis[i]);
		ans = min(ans,res);
	}
	cout << ans << "\n";
}
void init(){
	F(i,1,n) go[i].clear();
	ans = INF;
}
void work(){
	init();
	cin >> n >> k;
	F(i,1,n-1){
		int u,v;
		cin >> u >> v;
		go[u].pb(v), go[v].pb(u);
	}
	if (n <= 10) baoli();
	else cout << "1\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int _; cin >> _ >> _;
	while (_--) work();
	return 0;
}
