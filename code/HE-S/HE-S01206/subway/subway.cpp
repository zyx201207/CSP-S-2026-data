#include <bits/stdc++.h>
using namespace std;
int n,m,d,w[500005];
map<int,int> a[505];
int dis[500005];
bool vis[500005];
int solve(int x,int y){
	memset(vis,0,sizeof vis);memset(dis,0x7f,sizeof dis);
	dis[x] = 0;
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i = 1;i <= n;i++) if(a[i][u] != 0){
			for(auto j : a[i])
				if(!vis[j.first] && j.second != 0){dis[j.first] = min(dis[j.first],dis[u] + j.second);q.push(dis[j.first]);}
		}
		vis[u] = 1;
	}
	return dis[y];
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		while(k--){
			int x,y;
			cin >> x >> y;
			a[i][x] = y;
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << solve(x,y) + w[x] + w[y] << "\n";
	}
	
	return 0;
}
// ºÀ³àµÄÊ¯ 
