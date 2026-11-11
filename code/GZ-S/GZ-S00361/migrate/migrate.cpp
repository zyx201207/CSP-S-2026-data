//GZ-S00361 遵义四中 余学森 
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 10;

struct node {
	ll idx, dis;
	node (ll a, ll b):idx(a),dis(b){}
	bool operator>(const node&other) const{return dis>other.dis;}
};

bool vis[N];
ll c,t,n, d, x[N], dist[N],cnt[N],ans=0;
vector<ll> g[N];

void bfs(ll s){
	memset(cnt,0,sizeof cnt);
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	dist[s] =0;
	priority_queue<node,vector<node>,greater<node> >pq;
	pq.push(node(s,0));
	while(pq.size()){
		ll u = pq.top().idx, dis = pq.top().dis;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(cnt[u]==2)ans++;
		for(int i = 0; i < g[u].size(); i++){
			ll v=g[u][i],nd=dis+1;
			if(dist[v]>nd){
				dist[v]=nd;
				pq.push(node(v,nd));
				cnt[v]=1;
			}else if(dist[v]==nd){
				cnt[v]+=cnt[u];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		memset(x,0,sizeof x);
		ans=0;
		cin>>n>>d;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			cin >> x[i];
			for (int j = i - 1; j >= 1 && x[i] - x[j] <= d; j--) {
				g[j].push_back(i);
			}
		}
		for (int l = 1; l <= n; l++) bfs(l);
		cout<<ans<<'\n';
	}
	return 0;
}
