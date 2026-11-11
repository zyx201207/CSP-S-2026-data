#include <bits/stdc++.h>
using namespace std;

//typedefs
typedef long long ll;
typedef pair<ll, ll> pii;

//constants
const int N = 5e5 + 500 + 7;
const int M = 505;

//arrays
int w[N];
int k[N];

vector<pii> g[N];//[0,m)zhan, [m,m + n)xian

ll dis[M][N];
bool vis[N];
priority_queue<pii, vector<pii>, greater<pii> > pq;

//vars
ll n;
ll c, m, d, q;

void dij(ll s, ll t){
	while(pq.size()) pq.pop();
	for(int i = 0; i < n + m; ++i){
		dis[t][i] = LLONG_MAX;
	}
	memset(vis, 0, sizeof vis);
	
	dis[t][s] = 0;
	pq.push({dis[t][s], s});
	
	while(pq.size()){
		pii nxt = pq.top(); pq.pop();
		ll ndis = nxt.first, nid = nxt.second;
		vis[nid] = true;
		
		for(int i = 0; i < (int)g[nid].size(); ++i){
			pii vp = g[nid][i];
			ll w = vp.first, vid = vp.second;
			if(vis[vid]) continue;
			if(dis[t][vid] > dis[t][nid] + w){
				dis[t][vid] = dis[t][nid] + w;
				pq.push({dis[t][vid], vid});
			}
		}
	}
}



//main
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 0; i < m; ++i){
		cin >> w[i];
	}
	
	for(int i = 0; i < n; ++i){
		cin >> k[i];
		for(int j = 0; j < k[i]; ++j){
			ll aij,tij;
			cin >> aij >> tij;
			--aij;
			//cout << aij  << " " << m + i << endl;
			g[aij].push_back({tij, m+i});
			g[m+i].push_back({tij, aij});
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			dis[i][j] = LLONG_MAX;
		}
	}
	
	for(int i = 0; i < n; ++i){
		dij(i + m, i);
	}
	
	//cout << n << " " << m << endl;
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n + m; ++j){
			cout << dis[i][j] << " ";
		}cout << endl;
	}*/
	
	for(int i = 0; i < q; ++i){
		ll x, y;
		cin >> x >> y;
		--x, --y;
		ll ans = LLONG_MAX;
		
		//cout << g[x].size() <<" "<< g[y].size() << endl;
		
		for(int j = 0; j < g[x].size(); ++j){
			for(int k = 0; k < g[y].size(); ++k){
				ans = min(dis[g[x][j].second - m][g[y][k].second] + g[x][j].first + g[y][k].first, ans);
			}
		}
		ans += w[x] + w[y];
		
		printf("%lld\n",ans);
	}

	return 0;
}
