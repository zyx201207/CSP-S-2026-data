#include<bits/stdc++.h>
using namespace std;
struct node{
	int w,v,line;
	bool operator<(const node &o)const{
		return w>o.w;
	}
};
const int N=505,M=5e4+10;
vector<int> in_line[M];
int c,n,m,d,q,w[N],a[N][M],k[N],t[N][M],dist[N][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>a[i][j]>>x;
			t[i][a[i][j]]=x;
			in_line[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dist[i][j]=1e9;
		priority_queue<node> q;
		for(int u:in_line[x]){
			dist[u][x]=t[u][x];
			q.push({0,x,u});
		}
		while(!q.empty()){
			node u=q.top();
			q.pop();
//			cout<<u.v<<' '<<u.w<<' '<<u.line<<'\n';
			for(int i=1;i<=k[u.line];i++){
				if(a[u.line][i]!=u.v&&dist[u.line][a[u.line][i]]>dist[u.line][u.v]){
					dist[u.line][a[u.line][i]]=dist[u.line][u.v];
					q.push({u.w,a[u.line][i],u.line});
				}
			}
			for(int v:in_line[u.v]){
				if(dist[u.line][u.v]+t[v][u.v]+t[u.line][u.v]<dist[v][u.v]){
					dist[v][u.v]=dist[u.line][u.v]+t[v][u.v]+t[u.line][u.v];
					q.push({dist[v][u.v],u.v,v});
				}
			}
		}
		int ans=1e9;
		for(int u:in_line[y]) ans=min(ans,t[u][y]+dist[u][y]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
