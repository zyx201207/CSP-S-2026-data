#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5+5;
int c,n,m,d,q;
int station[MAXN]; //第i作车站到达出站口所用的时间 
bool flag[MAXN];
int small = LONG_LONG_MAX;

struct edge{
	int v,w;
}; 
vector<edge> e[10*MAXN]; // 邻接表存边 

struct Node{
	int node,cnt;
};

void dfs(int u,int end,int cnt){
	if(u == end){
		//cout << cnt << ' ';
		small = min(small,cnt);
		return;
	}
	if(cnt > small) return;
	for(int i=0 ; i<e[u].size() ; i++){
		int v = e[u][i].v,w = e[u][i].w;
		if(flag[v]) continue;
		flag[v] = 1;
		dfs(v,end,cnt+w);
		flag[v] = 0;
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1 ; i<=m ; i++) cin >> station[i];
	int xb = m;
	for(int i=1 ; i<=n ; i++){
		int r,sxb = xb+1;
		cin >> r;
		for(int j=1 ; j<=r ; j++){
			int a,t;
			cin >> a >> t;
			xb++;
			//cout << a << ' ' << xb << ' ' << t << endl;
			e[a].push_back({xb,t});
			e[xb].push_back({a,t});
		}
		for(int j=sxb+1 ; j<=sxb+r-1 ; j++){
			e[j-1].push_back({j,0});
			e[j].push_back({j-1,0});
		}
	}
	for(int i=1 ; i<=q ; i++){
		int u,v;
		cin >> u >> v;
		memset(flag,0,sizeof(flag));
		small = LONG_LONG_MAX;
		flag[u] = 1;
		dfs(u,v,0);
		cout << small+station[u]+station[v] << endl;
	}
//	for(int i=1 ; i<=xb ; i++){
//		cout << i << ':';
//		for(int j=0 ; j<e[i].size() ; j++){
//			int v = e[i][j].v;
//			cout << v << ' ';
//		}
//		cout << endl;
//	}
	return 0;
}
