#include<bits/stdc++.h>
using namespace std;
const long long INF=8e18+7;
const int maxn=1e4+7;
int c,t;

int n,d;
long long ans=0;
int x[maxn];
int vis[maxn];
struct node{
	int v;
	long long w;
	operator<(const node& o)const{
		return w>o.w;
	}
};
struct line{
	int cnt;
	long long w;
};
vector<node> v[maxn];
line dis[maxn][maxn];
priority_queue<node,vector<node>,less<node> > q;
void bfs(int start){
	memset(vis,0,sizeof vis);
	while(!q.empty()) q.pop();
	q.push({start,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(vis[t.v]&&dis[start][t.v].w<t.w) continue;
		vis[t.v]=1;
		dis[start][t.v].w=t.w;
		dis[start][t.v].cnt++;
		for(int i=0;i<v[t.v].size();i++){
			int vv=v[t.v][i].v,w=v[t.v][i].w;
			if(w<=d) q.push({vv,t.w+1});
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j].w=INF,dis[i][j].cnt=0;
	}
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			v[i].push_back({j,abs(x[i]-x[j])});
		}
	} 
	for(int i=1;i<=n;i++) bfs(i);
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j].cnt==2) ans++;
		}
	} 
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
