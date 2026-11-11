#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a;
	int t;
};
struct nodes{
	int l;
	int t;
};
int c,n,m,d,q;
vector<int>w;
vector<vector<nodes>>g;
vector<vector<node>>s;
void bfs(int str,int fin){
	
	vector<bool>vis(m + 1);
	queue<pair<int,int>>q;
	
	q.push({str,w[str]});
	vis[str] = true;
	int ans = 1e18;
	
	while(q.size() > 0){
		auto x = q.front();
		q.pop();
		if(x.first == fin){
			ans = min(ans,x.second + w[fin]);
			break;
		}
		for(auto t : g[x.first]){
			for(int i = 1;i <= s[t.l].size();i++){
				if(vis[s[t.l][i].a] == false){
					vis[s[t.l][i].a] = true;
					q.push({s[t.l][i].a,x.second + t.t + s[t.l][i].t});
				}
			}
		}
	}
	cout << ans << "\n"; 
}
void solve(){
	cin >> c >> n >> m >> d >> q;
	
	w.resize(m + 1);
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	
	g.resize(m + 1);
	s.resize(n + 1);
	for(int i = 1;i <= n;i++){
		int k; cin >> k;
		s[i].resize(k + 1);
		for(int j = 1;j <= k;j++){
			cin >> s[i][j].a >> s[i][j].t;
			g[s[i][j].a].push_back({i,s[i][j].t});
		}
	}
	
	for(int i = 1;i <= q;i++){
		int x,y; cin >> x >> y;
		bfs(x,y);
	}
	
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
}
