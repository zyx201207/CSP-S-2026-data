#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 510;
const ll M = 5e5+10;
const ll MAXN = 5e5+510;
ll c,n,m,d,Q,k[N],a[N][N],t[N][N],b[N];
ll f[N][N],dis[MAXN];
bool vis[MAXN];
struct node{
	ll to;
	ll w;
	bool operator < (const node &A)const{
		return w>A.w;
	}
};
vector<node> g[MAXN];
priority_queue<node> q;
ll main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> Q;
	for(ll i=1;i<=m;i++){
		cin >> b[i];
	}
	for(ll i=1;i<=n;i++){
		cin >> k[i];
		for(ll j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			g[a[i][j]].push_back({m+i,t[i][j]});
			g[m+i].push_back({a[i][j],t[i][j]});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m+n;j++){
			dis[j] = 1e18;
			vis[j] = 0;
		}
		dis[i+m] = 0;
		q.push({i+m,0});
		while(!q.empty()){
			node u = q.top();
			q.pop();
			if(vis[u.to])continue;
			vis[u.to] = 1;
			for(ll i=0;i<g[u.to].size();i++){
				ll to = g[u.to][i].to,w = g[u.to][i].w;
				if(dis[to]>dis[u.to]+w){
					dis[to] = dis[u.to]+w;
					q.push({to,dis[to]});
				}
			}
		}
		for(ll j=m+1;j<=m+n;j++)
			f[i][j-m] = dis[j];
	}
	for(ll i=1,x,y;i<=Q;i++){
		cin >> x >> y;
		ll ans = 1e18;
		for(ll j=0;j<g[x].size();j++){
			for(ll l=0;l<g[y].size();l++){
				ll t = g[x][j].w+g[y][l].w+f[g[x][j].to-m][g[y][l].to-m];
				ans = min(t,ans);
			}
		}
		ans += b[x]+b[y];
		cout << ans << '\n';
	}
	return 0;
}
//我们让大海淹没了嘴，享受着辛酸
