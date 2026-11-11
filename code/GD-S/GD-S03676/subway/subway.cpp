#include<bits/stdc++.h>//注意m是点数，n是线路数。 
#define int long long
using namespace std;
const int N = 1e3+10;
const int MAXN = 1e6+10;
const int INF = 1e18;
bool MB1;
int c,D,n,m,Q,a[N],k[MAXN],ton[N];
int dis[N][N][50],d[N][N];
bool vis[N][N][50];
bool MB2;
struct node{
	int num,s,u,now;
};
struct nodee{
	int v,now;
};
vector<nodee> e[N];
map<int,int> ita[N],ati[N];
map<int,int> W[N];
struct cmp{
	bool operator ()(const node &a,const node &b)const{
		return a.num > b.num;
	}
};
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>D>>Q;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=m;j++){
			for(int k = 1;k<=45;k++){
				dis[i][j][k] = INF;
				vis[i][j][k] = false;
			}
		}
	}
	for(int i = 1;i<=m;i++)
		cin>>a[i];
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		int last = 0;
		for(int j = 1;j<=k[i];j++){
			int x; cin>>x;
			int w; cin>>w;
			if(ati[x].find(i) == ati[x].end()){
				ati[x][i] = ++ton[x];
				ita[x][ton[x]] = i;
			}
			W[x][ati[x][i]] = w;
			if(last != 0){
				e[last].push_back({x,ati[x][i]});
				e[x].push_back({last,ati[last][i]});
			}
			last = x;
		}
	}
	priority_queue<node,vector<node>,cmp> q;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=ton[i];j++){
			q.push({W[i][j],i,i,j});
			dis[i][i][j] = W[i][j];
			
		}
	}
	while(!q.empty()){
		node f = q.top();
		q.pop();
		int u = f.u;
		int s = f.s;
		int now = f.now;
		if(vis[s][u][now]) continue;
		vis[s][u][now] = true;
		int len = e[u].size();
		for(int i = 0;i<len;i++){
			int v = e[u][i].v;
			int inow = e[u][i].now;
			int w = W[u][now] + W[u][ati[u][ita[v][inow]]];
			if(ita[u][now] == ita[v][inow]){
				if(dis[s][v][inow] > dis[s][u][now]){
					dis[s][v][inow] = dis[s][u][now];
					q.push({dis[s][v][inow],s,v,inow});
				}	
			}
			else{
				if(dis[s][v][inow] > dis[s][u][now] + w){
					dis[s][v][inow] = dis[s][u][now] + w;
					q.push({dis[s][v][inow],s,v,inow});
				}
			}
		}
	}
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=m;j++){
			int res = INF;
			for(int k = 1;k<=ton[j];k++){
				res = min(res,dis[i][j][k] + W[j][k]);
			}
			d[i][j] = res;
		}
	}
	while(Q--){
		int u; cin>>u;
		int v; cin>>v;
		int res = a[u] + a[v] + d[u][v];
		cout<<res<<'\n';
	}
	//还要加一个出站台 
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
