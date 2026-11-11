#include<bits/stdc++.h>
#include<vector>
#define int long long
#define fo(i,n) for(int i = 1;i<=n;i++)
#define foi(i,n,m) for(int i = n;i<=m;i++)
using namespace std;
const int N = 1e6 + 10;
int c,n,m,d,q,w[N];
struct node{
	int time,line;
};
vector<node> g[N];
vector<int> e[N];
int dis[550];
//int dp[N][N];
void dij(int u,int fa){
	foi(i,0,g[u].size()-1){
		int v = g[u][i].line;
		int w = g[u][i].time;
		if(v==fa) continue;
		if(dis[v]>dis[u]+w){
			dis[v] = dis[u]+w;
		}
		dij(v,u);
//		cout<<u<<" "<<v<<" "<<dis[v]<<" "<<dis[u]<<" "<<w<<endl;
	}
}
void dfsA(){
	memset(dis,0x3f,sizeof dis);
	fo(i,n){
		int a1,t1,a2,t2;
		cin>>a1>>a1>>t1>>a2>>t2;//a1到a2的站台时间 
		g[a1].push_back((node){t1+t2,a2});
		g[a2].push_back((node){t1+t2,a1});
//		dis[a1][a2] = t1+t2;
	}
	dis[1] = 0;
	dij(1,0);
	fo(i,q){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		cout<<dis[y]-dis[x]+w[x]+w[y]<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	fo(i,m) cin>>w[i];
		dfsA();
		return 0;
	fo(i,n){
		int k;
		cin>>k;
		fo(i,k){
			int a,t;
			cin>>a>>t;
			g[a].push_back({t,i});
			e[i].push_back(a);
		}
	}
	
}

