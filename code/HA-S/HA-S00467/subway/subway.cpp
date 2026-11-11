#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N=5010;
const int INF=1e18;
int c, n, m, d, q;
struct node{
	int to, len;
	bool operator<(const node& other)const{
		return len>other.len;
	}
};
vector<node>g[MAX_N];
int w[MAX_N];
int a[MAX_N][MAX_N];
int t[MAX_N][MAX_N];
int kn[MAX_N];

int dis[MAX_N];
bool vis[MAX_N];

void dij(int s){
	priority_queue<node>pq;
	pq.push({s, 0});
	for(int i=1;i<=m;i++)dis[i]=INF;
	for(int i=1;i<=m;i++)vis[i]=false;
	dis[s]=0;
	while(!pq.empty()){
		node tmp=pq.top();
		pq.pop();
		int to=tmp.to, len=tmp.len;
		if(vis[to])continue;
		vis[to]=true;
		for(node v:g[to]){
			if(dis[v.to]>len+v.len){
				dis[v.to]=len+v.len;
				pq.push({v.to, dis[v.to]});
			}
		}
	}
}


signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>kn[i];
		for(int j=1;j<=kn[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=kn[i];j++){
			for(int k=1;k<=kn[i];k++){
				if(j==k)continue;
				g[a[i][j]].push_back({a[i][k], t[i][j]+t[i][k]});
				g[a[i][k]].push_back({a[i][j], t[i][j]+t[i][k]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s, t;
		cin>>s>>t;
		dij(s);
		cout<<w[s]+w[t]+dis[t]<<'\n';
	}
	return 0;
}
