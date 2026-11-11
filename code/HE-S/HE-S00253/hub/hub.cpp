#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int c,t,n,k,ans,mx;
vector <int> g[N];
bool fl[N],vis[N];
int lo[N];
bool fll = 0;
void bfs(int s){
	for(int i = 1;i <= n;i ++)vis[i] = 0;
	queue < pair<int,int> > q;
	q.push({s,0});
	while(!q.empty()){
		auto u = q.front();q.pop();
		int x = u.first,w = u.second;
		if(vis[x])continue;vis[x] = 1;
		if(fl[x]){lo[s] = w;mx = max(mx,lo[s]);return;}
		for(auto y : g[x]){
			if(!vis[y])q.push({y,w + 1});
		} 
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> k;ans = 1e9;
		for(int i = 1;i <= n;i ++)g[i].clear();
		for(int i = 1,u,v;i < n;i ++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i = 1;i < (1ll << n);i ++){
			int num = 0;mx = 0;
			for(int j = 0;j < n;j ++){
				if((1ll << j) & i)num ++,fl[j + 1] = 1;
				else fl[j + 1] = 0;
				lo[j + 1] = 1e9;
			}
			if(num == k){
				for(int j = 1;j <= n;j ++)bfs(j);	
				ans = min(ans,mx);
			}
		}
		cout << ans << '\n';
	}
}
