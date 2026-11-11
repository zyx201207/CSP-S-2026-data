#include <bits/stdc++.h>
using namespace std;
const int N = 500100, M = 510;
typedef long long ll;
int tc, n, m, d, q;
ll w[N];
vector<int> a[N], sub[N];
vector<pair<int, ll>> e[N + M];
ll dist[N], answer[1010][1010];
set<pair<ll, int>> st;
int main(){
//	freopen("subway4.in", "r", stdin);
//	freopen("sub.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> tc >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i= 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int v;
			cin >> v;
			a[i].push_back(v);
			int ti;
			cin >> ti;
			sub[v].push_back(i);
			e[m + i].push_back({v, ti});
			e[v].push_back({i + m, ti});
		}
	}
	if(m <= 1000){
		for(int k = 1; k <= m; k++){
			for(int i = 1; i <= m + n; i++)
				dist[i] = 1e18;
			dist[k] = 0;
			for(int i = 1; i <= m + n; i++)
				st.insert({dist[i], i});
			while(!st.empty()){
				ll x = st.begin()->first, y = st.begin()->second;
				st.erase(st.begin());
				for(auto D : e[y]){
					ll u = D.first, v = D.second;
					if(dist[u] > x + v){
						st.erase({dist[u], u});
						dist[u] = x + v;
						st.insert({dist[u], u});
					}
				}
			}
			for(int i = 1; i <= m; i++)
				answer[k][i] = w[k] + dist[i] + w[i];
		}
		for(; q--; ){
			int A, B;
			cin >> A >> B;
			cout << answer[A][B] << '\n'; 
		}
		return 0;
	}
	for(; q--; ){
		int A, B;
		cin >> A >> B;
		for(int i = 1; i <= m + n; i++)
			dist[i] = 1e18;
		dist[A] = 0;
		for(int i = 1; i <= m + n; i++)
			st.insert({dist[i], i});
		while(!st.empty()){
			ll x = st.begin()->first, y = st.begin()->second;
			st.erase(st.begin());
			for(auto D : e[y]){
				ll u = D.first, v = D.second;
				if(dist[u] > x + v){
					st.erase({dist[u], u});
					dist[u] = x + v;
					st.insert({dist[u], u});
				}
			}
		}
		cout << dist[B] + w[A] + w[B] << '\n';
	}
	return 0;
}
