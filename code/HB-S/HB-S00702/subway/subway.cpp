#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sug=5e3+5;
int c,n,m,d,Q;
struct edge{
	int to,val;
	bool operator <(const edge &x) const{
		return to>x.to;
	}
};
vector <edge> e[sug];
int dis[sug];
bool vis[sug];
priority_queue <edge> q;
int dp[sug][sug];
void dj(int s){
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		edge lyb=q.top();
		q.pop();
		int u=lyb.to;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			edge v=e[u][i];
			int to=v.to,val=v.val;
			if(dis[to]>=dis[u]+val){
				dis[to]=dis[u]+val;
				if(!vis[to]) q.push({to,dis[to]});
			}
		}
	}
}
signed main(){
	memset(dp,0,sizeof(dp));
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	//1-m groud
	//m+1-2*m station
	//
	int idx=0;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		e[++idx].push_back({m+idx,w});
		e[m+idx].push_back({idx,w});
	}
	idx+=m;
	for(int i=1;i<=n;i++){
		int k,a[sug],t[sug];
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			e[++idx].push_back({a[j]+m,t[j]});
			e[a[j]+m].push_back({idx,t[j]});
			if(j!=1){
				e[idx].push_back({idx-1,0});
				e[idx-1].push_back({idx,0});
			}
		}
	}
	for(int i=1;i<=m;i++){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dj(i);
		for(int j=1;j<=idx;j++) dp[i][j]=dis[j];
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<'\n';
	}
/*	while(Q--){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		dj(x);
		cout<<dis[y]<<'\n';
	}*/
	return 0;
}
