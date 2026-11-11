#include<bits/stdc++.h>
#define E emplace_back
#define chm(X , Y) (X = min(X , Y))
#define int long long
using namespace std;

const int N = 505 , M = 500100;
int _c , n , m , d , q , w[M] , k[N] , dis[N][N];
vector<int> a[N] , t[N] , a_[M] , t_[M];

signed main(){
	freopen("subway.in" , "r" , stdin) , freopen("subway.out" , "w" , stdout);
	// freopen("data.in" , "r" , stdin) , freopen("data.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	cin>>_c>>n>>m>>d>>q;
	for(int i = 1; i <= m; ++i) cin>>w[i];
	for(int i = 1; i <= n; ++i){
		cin>>k[i] , a[i].resize(k[i]) , t[i].resize(k[i]);
		for(int j = 0 , u , v; j < k[i]; ++j)
			cin>>u>>v , a[i][j] = u , t[i][j] = v , a_[u].E(i) , t_[u].E(v);
	}
	memset(dis , 0x3f , sizeof(dis));
	for(int i = 1; i <= n; ++i) dis[i][i] = 0;
	for(int i = 1; i <= m; ++i){
		int j = a_[i].size();
		for(int u = 0; u < j; ++u) for(int v = 0; v < u; ++v)
			chm(dis[a_[i][u]][a_[i][v]] , t_[i][u] + t_[i][v]) , 
			chm(dis[a_[i][v]][a_[i][u]] , t_[i][u] + t_[i][v]);
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				chm(dis[i][j] , dis[i][k] + dis[k][j]);
	while(q--){
		int x , y , z1 , z2 , v = 1e18;
		cin>>x>>y , z1 = a_[x].size() , z2 = a_[y].size();
		for(int i = 0; i < z1; ++i)
			for(int j = 0; j < z2; ++j)
				v = min(v , t_[x][i] + t_[y][j] + dis[a_[x][i]][a_[y][j]]);
		cout<<(v + w[x] + w[y])<<'\n';
	}

	return 0;
}