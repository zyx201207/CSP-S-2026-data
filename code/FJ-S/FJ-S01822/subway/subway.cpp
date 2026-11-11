#include<bits/stdc++.h>
using namespace std;
const int N=500010; 
struct node{
	int v,w; 
}; 
struct line{
	int u,v,w;
	bool operator < (const line &W)const{
		return w<W.w; 
	} 
};
int c,n,m,d,q;
int w[N];
int l[510][N];
bool st[N]; 
int dis[N]; 
vector<node>g[N]; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	} 
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;cin>>a>>l[i][a]; 
			for(int z=1;z<=m;z++){
				if(l[i][z]==0)continue; 
				node t;				 
				t.w=l[i][z]+l[i][a];
				t.v=z;
				g[a].push_back(t);
				t.v=a; 
				g[z].push_back(t);
			} 
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		priority_queue<line>qu;
		st[x]=1,dis[x]=0;  
		for(int i=0;i<g[x].size();i++){
			line t;
			t.u=x,t.v=g[x][i].v,t.w=g[x][i].w;
			qu.push(t);
		} 
		while(qu.size()){
			line t=qu.top();qu.pop();
			int u=t.u,v=t.v,w=t.w; 
			if(st[v])continue;
			st[v]=1,dis[v]=w; 
			for(int i=0;i<g[v].size();i++){
				t.u=v,t.v=g[v][i].v,t.w=g[v][i].w+dis[v]; 
				qu.push(t);
			} 
		}
		cout<<w[x]+w[y]+dis[y]<<'\n';
		memset(dis,0,sizeof dis);
		memset(st,0,sizeof st); 
	} 
	return 0;
}
