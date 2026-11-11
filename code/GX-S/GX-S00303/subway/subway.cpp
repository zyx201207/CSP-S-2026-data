#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 5 , M = 5e5 + 5 , K = 1e7 + 2;
int c , n , m , d , q , cnt;
ll w[M] , k[N] , wi[M] , dis[M];
vector<pair<int , ll> > g[M];
vector<int> st[M];
struct node{
	int s , t;
	ll ans;
	int id;
}Q[M];
void dij(int s){
	g[0].clear();
	for(auto v : st[s]){
		g[0].push_back({v , wi[v]});
	}
	fill(dis , dis + cnt + 1 , LLONG_MAX);
	dis[0] = 0;
	priority_queue<pair<ll , int> > q;
	q.push({0 , 0});
	while(!q.empty()){
		 int u = q.top().second;
		 q.pop();
		 for(auto to : g[u]){
			 int v = to.first , w = to.second;
			 if(dis[v] > dis[u] + w){
				 dis[v] = dis[u] + w;
				 q.push({dis[v] * -1 , v});
			 }
		 }
	}
	return;
}
ll getmin(int s , int t){
	ll minn = LLONG_MAX;
	for(auto ed : st[t]){
		minn = min(minn , dis[ed] + wi[ed]);
	}
	return minn + w[s] + w[t];
}
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; ++i) cin >> w[i];
	for(int i = 1 ; i <= n ; ++i){
		cin >> k[i];
		for(int j = 1 ; j <= k[i] ; ++j){
			int ai;
			ll ti;
			cin >> ai >> ti;
			st[ai].push_back(++cnt);
			wi[cnt] = ti;
			if(j > 1){
				g[cnt - 1].push_back({cnt , 0});
				g[cnt].push_back({cnt - 1 , 0});
			}
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		vector<int> pts;
		for(int li : st[i]){
			pts.push_back(li);
		}
		for(int j = 0 ; j < pts.size() - 1 ; ++j){
			int u = pts[j];
			int v = pts[j + 1];
			g[u].push_back({v , wi[u] + wi[v]});
			g[v].push_back({u , wi[u] + wi[v]});
		}
	}
	/*
	for(int i = 1 ; i <= cnt ; ++i){
		cout << "u = " << i << " | ";
		for(auto v : g[i]){
			cout << v.first << " " << v.second << " | ";
		}
		cout << '\n';
	}
	*/
	
	
	for(int i = 1 ; i <= q ; ++i){
		cin >> Q[i].s >> Q[i].t;
		Q[i].id = i;
	}
	sort(Q + 1 , Q + q + 1 , [](const node& x , const node& y){
		return x.s < y.s;
	});
	int s = 0;
	for(int i = 1 ; i <= q ; ++i){
		if(Q[i].s != s){
			s = Q[i].s;
			dij(s);
		}
		Q[i].ans = getmin(Q[i].s , Q[i].t);
	}
	sort(Q + 1 , Q + q + 1 , [](const node& x , const node& y){
		return x.id < y.id;
	});
	for(int i = 1 ; i <= q ; ++i)
		cout << Q[i].ans << '\n';
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/
