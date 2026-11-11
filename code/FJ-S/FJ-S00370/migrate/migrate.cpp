#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int , int>
const int N = 2e5 + 10;
vector<int> g[N] , fa[N];
int n , d;
int x[N];
bool st[N];
int dd[N];
void add(int a , int b){
	g[a].push_back(b); 
}
bool bfs(int s , int t){
	for(int i = 1 ; i <= n ; i ++) dd[i] = 1e18;
	dd[s] = 0;
	queue<int> q;
	q.push(s);
	while(q.size()){
		auto u = q.front();
		q.pop();
		if(t == u) return 1;
		for(auto x : g[u]){
			if(dd[x] > dd[u] + 1){
				dd[x] = dd[u] + 1;
				fa[x].push_back(u);
				q.push(x);
			}
		}
	} 
}
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c , T;
	cin >> c >> T;
	while(T --){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++) cin >> x[i];
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= n ; j ++){
				int s = abs(x[i] - x[j]);
				if(s <= d){
					add(i , j);
					add(j , i);
				}
			}
		}
		if(n <= 500){
			int ans = 0;
			for(int i = 1 ; i <= n ; i ++){
				for(int j = 1 ; j <= n ; j ++){
					if(i != j){
						bfs(i , j);
						if(fa[j].size() == 2) ans ++; 
					}
				}
			}
			cout << ans << '\n';
		}
		cout << 0 << '\n';
	}
	return 0;
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
