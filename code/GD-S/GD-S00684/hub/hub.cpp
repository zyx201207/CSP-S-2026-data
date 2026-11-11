#include <bits/stdc++.h>
using namespace std;

#define int long long
#define re register 

struct node{
	int u;
	int v;
};

const int inf = 0x3f3f3f3f3f3f3f3f;
int _,t,n,k,d[1000001],ans;
bool cho[1000001],vis[1000001];
vector<node> e[1000001];

inline void dfs(const int &x,const int &chsd){
	if (chsd == k){
		memset(vis,0,sizeof vis);
		int cnt = 0;
		for (int i = 1;i <= n;i++){
			if (!vis[i] && cho[i]){
				if (cnt == 2){
					return ;
				}
				cnt++;
				queue<int> q;
				q.push(i);
				while (q.size()){
					int f = q.front();
					q.pop();
					if (!cho[f] || vis[f]){
						continue;
					} 
					vis[f] = 1;
					for (auto j : e[f]){
						if (!vis[j.v] && cho[j.v]){
							q.push(j.v);
						}
					}
				}
			}
		}
		queue<node> q;
		for (int i = 1;i <= n;i++){
			if (cho[i]){
				q.push({i,0});
			}
		}
		memset(d,0,sizeof d);
		memset(vis,0,sizeof vis);
		int nowans = 0;
		while (q.size()){
			node f = q.front();
			q.pop();
			if (vis[f.u]){
				continue;
			}
			d[f.u] = f.v;
			nowans = max(nowans,d[f.u]);
			if (nowans >= ans){
				return ;
			}
			vis[f.u] = 1;
			for (auto i : e[f.u]){
				if (!vis[i.v]){
					q.push({i.v,f.v + 1});
				}
			}
		}
		ans = nowans;
		return ;
	}
	if (x > n || chsd > k){
		return ;
	}
	cho[x] = 1;
	dfs(x + 1,chsd + 1);
	cho[x] = 0;
	dfs(x + 1,chsd);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin >> _ >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1;i <= n;i++){
			e[i].clear();
		}
		for (int i = 1;i < n;i++){
			int u,v;
			cin >> u >> v;
			e[u].push_back({u,v});
			e[v].push_back({v,u});
		}
		ans = inf;
		dfs(1,0);
		cout << ans << '\n';
	} 
	return 0;
} 
//Çó¸ö15pts°É... 
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
