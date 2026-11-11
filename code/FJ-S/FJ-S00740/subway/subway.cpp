#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 502;
const int Q = 100002;
const int M = 500002;
const int D = 22;
int c,n,m,d,q;
int tin[M];//di4 tie3 kou3 <--> zhan4 tin1
vector<pair<int,int> >th[M];//is m in n?if so,how long?
//        id(N),dis
int link_n[N][N];
//bool vis_a[N];//vis_b[N];

int vis[N];
struct Road{
	int v,w,nxt;
}e[N*N];
int h[N],tot;
void add(int u,int v,int w){
	e[++tot] = {v,w,h[u]};
	h[u] = tot;
}
//int app;
void dfs(int start,int x,int dis){
	if (vis[x])return;
	vis[x] = true;
//	app++;
	link_n[start][x] = min(dis,link_n[start][x]);
	link_n[x][start] = link_n[start][x];
	
//	for(int i = 1; i <= app; i++){
//		cout<<"    ";
//	}cout<<start<<' '<<x<<' '<<dis<<endl;
	for(int i = h[x]; i > 0; i = e[i].nxt ){
		dfs(start,e[i].v,dis + e[i].w);
	}
	vis[x] = false;
//	app--;
}
void solve(){
	for(int i = 1; i <= n; i++){
		dfs(i,i,0);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++){
		cin>>tin[i];
		th[i].push_back({0,0});
	}
	
	for(int i = 1; i <= n; i++){
		int kt;
		cin>>kt;
		for(int j = 1; j <= kt; j++){
			int v,w;
			cin>>v>>w;
			th[v].push_back({i,w});
		}
		for(int j = 1; j <= n; j++){
			link_n[i][j] = 1000000000000000000;
		}
	}
	for(int i = 1; i <= m; i++){//5e5
		int tt2 = th[i].size();
		for(int j = 1; j < tt2; j++){//20
			int tt3 = th[i].size();
			for(int k = j+1; k < tt3; k++){//20
				int x,y,dx,dy;
				x = th[i][j].first;
				y = th[i][k].first;
				dx = th[i][j].second;
				dy = th[i][k].second;
				link_n[x][y] = min(link_n[x][y],dx+dy);
				link_n[y][x] = link_n[x][y];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(link_n[i][j] != 1000000000000000000){
				add(i,j,link_n[i][j]);
				add(j,i,link_n[i][j]);
			}
		}
	}
	solve();
	
	
	
	for(int i = 1; i <= q; i++){
		int ans = -1;
		int x,y;
		cin>>x>>y;
		for(int j = 1; j < th[x].size(); j++){
			for(int k = 1; k < th[y].size(); k++){
				int temp = th[x][j].second + th[y][k].second + tin[x] + tin[y] + link_n[th[x][j].first][th[y][k].first];
				if(ans == -1){
					ans = temp;
				}else{
					ans = min(ans,temp);
				}
			}      
		}
		cout<<ans<<endl;
	}
	return 0;
} 