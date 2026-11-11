#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
int c,n,m,d,Q;
int w[N];
struct edge{
	int id,w;
};
int cnt[N];
vector<edge> g[505];
vector<int> line[N];
int mp[505][N];
struct query{
	int l,r,id;
}qp[N];
int qqq[N];

bool cmp(query x1,query x2){
	return x1.l<x2.r;
}
bool operator<(edge x1,edge x2){
	return x1.w>x2.w;
}
int ans[N];
int dis[505];
bool vis[505];
priority_queue<edge> q;
void dij(int s){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	q.push({s,0});
//	cout<<"%%%"<<s<<'\n';
	while(!q.empty()){
		edge tmp=q.top();
		q.pop();
		int u=tmp.id;
//		cout<<u<<" "<<tmp.w<<endl;
		if(vis[u]) continue;
		dis[u]=tmp.w;
		vis[u]=1;
		for(edge v:g[u]){
			if(!vis[v.id]) q.push({v.id,tmp.w+v.w});
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			int x,l;
			cin>>x>>l;
			line[x].push_back(i);
			mp[i][x]=l;
		}
	}
	for(int i=1;i<=m;i++){
		if(line[i].size()<=1) continue;
		for(int j=0;j<line[i].size();j++){
			for(int k=j+1;k<line[i].size();k++){
				g[line[i][j]].push_back({line[i][k],mp[line[i][j]][i]+mp[line[i][k]][i]});
				g[line[i][k]].push_back({line[i][j],mp[line[i][j]][i]+mp[line[i][k]][i]});
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int s,e;
		cin>>s>>e;
		if(s>e) swap(s,e);
		qp[i].l=s,qp[i].r=e;
		qp[i].id=i;
	}
	memset(ans,0x3f,sizeof ans);
	int pos=1;
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=Q;j++){
			int L=qp[j].l,R=qp[j].r;
			if(mp[i][L]){
				for(int p:line[R]){
					ans[j]=min(ans[j],mp[i][L]+w[L]+w[R]+mp[p][R]+dis[p]);
				}
			}
		} 
	}
	for(int i=1;i<=Q;i++) cout<<ans[i]<<'\n';
	return 0;
} 
