#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e6 + 10;
int test, C;
int n, m;
vector<pair<ll, ll> > edges[N];

set<pair<ll, ll> > s;
ll d[N], a[N], ans[N];
inline void Dijkstra(int root){
	s.clear();
	fill(d + 1, d + n + 1, LONG_LONG_MAX);
	memset(ans, 0, sizeof(ans));
	
	d[root] = 0;
	for(int i = 1; i <= n; i++)
		s.insert(make_pair(d[i], i));
	ans[root] = 1;
	
	while(!s.empty()){
		int x = s.begin()->second;
		s.erase(s.begin());
		
		for(auto Y : edges[x]){
			auto y = Y.first, w = Y.second;
			if(d[y] > d[x] + w){
				s.erase(make_pair(d[y], y));
				d[y] = d[x] + w;
				s.insert(make_pair(d[y], y));
			}
			if(d[y] == d[x] + w){
				ans[y] += ans[x];
			}			
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);	
	
	scanf("%d%d", &C, &test);
	while(test--){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		for(int i = 1; i <= n; i++) edges[i].clear();
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				int D = abs(a[j] - a[i]);
				if(D <= m){
					edges[i].push_back(make_pair(j, D));
					edges[j].push_back(make_pair(i, D));
				}
			}
		}
		Dijkstra(1);
		
		ll sum = 0;
		for(int i = 1; i <= n; i++)
			if(ans[i] == 2) sum++;
		printf("%lld\n", sum);
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
