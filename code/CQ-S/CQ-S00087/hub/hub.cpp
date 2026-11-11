#include<bits/stdc++.h>
#define LL long long
#define PII pair <LL, LL>
using namespace std;
bool bbb;
const LL N = 1e6 + 5, M = 105;
LL c, n, k, m,ans;
LL dep[N], sz[N], f[M][M][2], tmp[M][M], t[N], vis[N];
PII e[N];
vector <LL> p[N];
struct Node{
	LL x,dis;
	bool operator < (Node A) const{
		if(A.x>m||x>m)return x>m;
		else return  A.dis<dis;
	}
};
priority_queue<Node> q; 
//void dfs(LL u, LL fa) {
//	dep[u] = maxdep[u] = dep[fa] + 1;
//	sz[u] = 1;
//	f[u][1][dep[u]] = 1;
//	for(LL i : p[u]) if(i != fa) {
//		dfs(i, u);
//		for(LL j = 0; j <= n; j ++ ) for(LL k = 0; k <= n; k ++ ) tmp[j][k] = 0; 
//		for(LL j = 0; j <= sz[u]; j ++ ) for(LL k = 0; k <= sz[i]; k ++ ) {
//			for(LL l1 = dep[u]; l1 <= n; l1 ++ ) {
//				for(LL l2 = dep[u]; l2 <= n; l2 ++ ) {
//					tmp[j + k][l]
//				}
//			}
//		}
//		for(LL j = 1; j <= n; j ++ ) {
//			for(LL k = 1; k <= n; k ++ ) {
//				if(maxdep[i] - dep[u] + k - dep[u] <= )
//			}
//		}
//		for(LL j = 0; j <= n; j ++ ) for(LL k = 0; k <= n; k ++ ) f[u][j][k] = tmp[j][k];
//		sz[u] += sz[i];
//		maxdep[u] = max(maxdep[u], maxdep[i]);
//	}
//}
LL dfs1(LL u, LL fa, LL dep) {
	if(t[u])return dep;
	LL res=1e18;
	for(LL i:p[u])if(i!=fa){
		res=min(res,dfs1(i,u,dep+1));
	}
	return res;
}
void solve() {
	ans = 1e18;
	memset(f, 0, sizeof f);
	for(LL i = 1; i <= n; i ++ ) p[i].clear();
	cin >> n >> k;
	for(LL i = 1, x, y; i < n; i ++ ) {
		cin >> x >> y;
		p[x].push_back(y);
		p[y].push_back(x);
		e[i]={x,y};
	}
	if(c <= 3){
		for(LL i=0;i<1<<n;i++){
			LL cnt=0;
			for(LL j=1;j<=n;j++)cnt+=i>>j-1&1;
			if(cnt!=k)continue;
			for(LL j=1;j<n;j++)if(i>>e[j].first-1&1 &&  i>>e[j].second-1&1) cnt--;
			if(cnt >2)continue;
			for(LL j=1;j<=n;j++)t[j]=i>>j-1&1;
			LL res=0;
			for(LL j=1;j<=n;j++)res=max(res,dfs1(j,0, 0));
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
		return ;
	}
	if(c == 13 || c == 14) {
		ans=0;
		for(LL i=1;i<=n;i++)dep[i]=-1;
		m=n/2;
		q.push({m/3,0});
		q.push({m/3*2,0});
		dep[m/3]=dep[m/3*2]=0;
		while(q.size()){
			LL u=q.top().x,udis=q.top().dis;
			q.pop();
			if(udis>dep[u])continue;
			if(k){
				dep[u]=0;
				k--;
			}
			ans=max(ans,dep[u]);
			for(LL i:p[u])if(dep[i]==-1){
				dep[i]=dep[u]+1;
				q.push({i,dep[i]});
			}
		}
		cout<<ans<<'\n';
		return;
	}
//	dfs(1, 0);
	
}
bool eee;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cerr << abs(&bbb - &eee) / 1024.0 / 1024 << '\n';
	LL t;
	cin >> c >> t;
	while(t -- ) solve();
	return 0;
}

