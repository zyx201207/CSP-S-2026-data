#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 520,M = 5e5 +10;
int c,n,m,d,q,val[M],head[M],idx,dist[N][N],a[M];
struct graph{
	int id,to,nxt;
}G[M << 1],nG[M << 1];
struct node{
	int id,tim;
};
vector<node>cost[N];/*从站厅i走到路线j的站台*/
void floyd(){
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			if(dist[i][k] == 1e18)continue;
			for(int j = n;j >= 1;j--){
				if(dist[k][j] ==1e18)continue;
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> val[i];
		for(int j = 1;j <= m;j++){
			dist[i][j] = 1e18;
			if(i == j){
				dist[i][j] = 0;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int t;
			cin >> a[j] >> t;
			cost[a[j]].push_back({i,t});
		}
	}
	
//	for(int i = 1;i <= m;i++){
//		for(int j = 0;j < cost[i].size();j++){
//			cerr << cost[i][j].id << ' ' << cost[i][j].tim << '\n';
//		}
////		cerr << i;
//		cerr << '\n';
//	}
//	cerr<<"here\n";
	for(int i = 1;i <= m;i++){
		
		for(int j = 0;j < cost[i].size()-1;j++){//cerr << j;
			for(int k = j + 1;k < cost[i].size();k++){
				int tmp = cost[i][j].tim + cost[i][k].tim;
				int u = cost[i][j].id,v = cost[i][k].id;
				if(u < v)swap(u,v);
				dist[u][v] = min(dist[u][v],tmp);
//				cerr << u << ' ' << v << ' ' << dist[u][v] <<' '<<tmp <<  '\n';
			}
		}
	}
	floyd();
//	cout << "here\n";
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cerr << dist[i][j] << ' ';
//		}
//		cerr << '\n';
//	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int spd = val[x] + val[y],tmp = 1e18;
		if(x < y){
			swap(x,y);
		}
		for(node u : cost[x]){
			for(node v : cost[y]){
//				cerr << dist[max(u.id,v.id)][min(u.id,v.id)] + v.tim + u.tim <<' '<< u.id<<' ' << v.id <<'\n';
				tmp = min(dist[max(u.id,v.id)][min(u.id,v.id)] + v.tim + u.tim,tmp);
			}
		}
		cout << spd + tmp << '\n' ;
	}
	return 0;
} 
//Oct31==Dec25?
