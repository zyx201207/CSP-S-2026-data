#include<bits/stdc++.h>
using namespace std;
const int maxm=5e4+7;
const int maxp=1e4+7;
int c,n,m,d,Q;
int k;
long long w[maxm];
long long dis[maxp][maxp];
int vis[maxp];
struct node{
	int v;
	long long w;
	operator<(const node& o)const{
		return w>o.w;
	}
};
vector<node> ve[maxp];
priority_queue<node,vector<node>,less<node> > q;
void bfs(int start){
	memset(vis,0,sizeof vis);
	while(!q.empty()) q.pop();
	q.push({start,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(vis[t.v]) continue;
		vis[t.v]=1;
		dis[start][t.v]=t.w;
		for(int i=0;i<ve[t.v].size();i++){
			int v=ve[t.v][i].v,w=ve[t.v][i].w;
			if(!vis[v]) q.push({v,t.w+w});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int tot=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		int now,lst;
		for(int j=1;j<=k;j++){
			int a;
			long long t;
			cin>>a>>t;
			now=++tot;
			ve[a].push_back({now,t});
			ve[now].push_back({a,t});
			if(j>1){
				ve[now].push_back({lst,0});
				ve[lst].push_back({now,0});
			}
			lst=now;
		}
	}
	for(int i=1;i<=m;i++) bfs(i);
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
} 
