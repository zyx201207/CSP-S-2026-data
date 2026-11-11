#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < int , int > pii;
struct edge{
	ll dis,u,num;
	bool operator > (const edge a)const {
		return dis < a.dis;
	}
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	ll inf = 0x3f3f3f3f3f3f3f3f;
	cin >> c >> n >> m >> d >> q;
	vector < vector < vector < ll > > > dist(m + 1,vector < vector < ll > > (m + 1,vector < ll > (n + 1,inf)));
	vector < vector < ll > > u(n + 1,vector < ll > (m + 1));
	vector < ll > w(m + 1);
	vector < vector < pii > > g(n + 1);// f:v s:ÏßÂ·
	for(int i = 1;i <= m;i++)cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		int last;
		cin >> last;
		cin >> u[i][last];
		for(int j = 2;j <= k;j++){
			int v;
			cin >> v;
			cin >> u[i][v];
			g[last].push_back({v,i});
		}
	}
	
	priority_queue < edge ,vector < edge > ,greater < edge > > pq;
	while(q--){
		int s,t;
		cin >>s >> t;
		if(dist[s][s][0] == 0){
			cout << dist[s][s][t] << '\n';
			continue;
		}
		pq.push({0,s,0});
		
		while(!pq.empty()){
			edge o = pq.top();
			
			pq.pop();
			
			if(dist[s][o.u][o.num] != o.dis && o.u != s)continue;
			for(pii oi : g[o.u]){
				int v = oi.first,num = oi.second;
				if(num == o.num){
					if(dist[s][v][num] <= o.dis)continue;
					dist[s][v][num] = o.dis;
					pq.push({dist[s][v][num],v,num});
				}else{
					ll val = o.dis + u[o.num][o.u] + u[num][o.u];
					if(dist[s][v][num] <= val)continue;
					dist[s][v][num] = val;
					pq.push({val,v,num});
				}
			}
		} 
		ll ans = inf;
		for(int i = 1;i <= n;i++)ans = min(ans,dist[s][t][i] + u[i][t]);
		cout << ans + w[s] + w[t]<< '\n';
	}
}
