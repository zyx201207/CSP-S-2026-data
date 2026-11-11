#include <bits/stdc++.h>

using namespace std;
const int MAXN = 500,MAXK = 5e5 + 5,MAXQ = 1e5 + 5,MAXM = 5e5 + 5; 

int c,n,m,d,q;
int w[MAXM],k[MAXN];
vector<pair<int,int>> g[MAXN];

/*struct node{
	int u,v,id;
};

vector<node> route;
int mint(int st,int en){
	if(st == en){
		return 
	}
	for(int i = 1;i <= n;i++){
		for(auto p : a[i]){
			if(p == en)	continue;
			mint(p,en);
			vis[]
		}
			mint(p,en);
	}
	
}*/

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	} 
	int u,v,l[3];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		cin >> u >> l[0];
		cin >> v >> l[1];
		v[u].push_back({v,l[0]});
		v[v].push_back({u,l[1]});
	}

	for(int i = 1;i <= q;i++){
		cin >> x >> y;
		queue<int> q;
		vector<int> dist(n + 5,-1);
		dist[x] = 0;
		q.push(x);
		while(!q.empty()){
			int u = q.front();q.pop();
			for(auto p : g[u]){
				int v = p.first,k = p.second;
				if(dist[v] == -1)
					dist[v] = dist[u] + k;
			}
		} 
		long long ans = w[x] + w[y] + dist[y];
		cout << ans << '\n'; 
	}
	return 0;
} 
