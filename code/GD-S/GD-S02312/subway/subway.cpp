#include<bits/stdc++.h>
using namespace std;
int c,n,M,d,q,w[500005],ans[500005],t[505][500005],vis[505][50005];
struct Node{
	int id,t,num;
	bool flag;
};
vector<int> g[505];
int bfs(int x,int y){
	memset(ans,0x3f3f3f3f,sizeof(ans));
	memset(vis,0x3f3f3f3f,sizeof(vis));
	queue<Node> q;
	q.push({x,0,0,0});
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(int i = 1;i <= n;i++){
			if(i == u.num){
				continue;
			}
			for(auto j : g[i]){
				if(u.id == j){
					if(u.t + t[u.num][j] + t[i][j] < vis[i][j]){
						vis[i][j] = u.t + t[u.num][j] + t[i][j];
						q.push({j,u.t + t[u.num][j] + t[i][j],i,1});
					}
				}
			}
		}
		for(auto i : g[u.num]){
			if(u.flag == 0){
				break;
			}
			if(u.t < vis[u.num][i]){
				vis[u.num][i] = u.t;
				ans[i] = min(ans[i],u.t);
				q.push({i,u.t,u.num,0});
			}
		}
	}
	return ans[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> M >> d >> q;
	for(int i = 1;i <= M;i++){
		cin >> w[i];
	}
	for(int i = 1,k;i <= n;i++){
		cin >> k;
		for(int j = 1,x;j <= k;j++){
			cin >> x >> t[i][x];
			g[i].push_back(x);
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << (bfs(x,y) + w[x] + w[y]) << '\n';
	}
	return 0;
}
