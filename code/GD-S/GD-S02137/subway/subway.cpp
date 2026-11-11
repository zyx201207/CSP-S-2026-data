#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = pair<ll,ll>;

constexpr ll N = 510;
constexpr ll M = 5e5+10;
int c,n,m,d,q;
ll a[M],dist[M*2];
vector<PLL> g[M*2];
bool vis[M*2];

ll solve(int st,int ed){
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	priority_queue<PLL,vector<PLL>,greater<PLL>> q;
	q.push({0,st});
	while(q.size()){
		PLL t = q.top();
		q.pop();
		vis[t.second] = true;
		for(PLL it:g[t.second])
			if(!vis[it.first])
				dist[it.first] = min(dist[it.first],t.first+it.second),
				q.push({dist[it.first],it.first});
	}
	return dist[ed];
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	int k,x,y;
	for(int i=1;i<=m;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> x >> y;
			g[m+i].push_back({x,y});
			g[x].push_back({m+i,y});
		}
	}
	while(q--){
		cin >> x >> y;
		cout << solve(x,y)+a[x]+a[y] << '\n';
	}
	return 0;
}
