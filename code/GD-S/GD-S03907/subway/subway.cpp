#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N=5e5+50;
int w[N];
struct node{
	int v,id;
};
vector<node> e[N];
int ww[N][25]; 
int minn=INT_MAX;
int pre[N];
int vis[N];
void dfs(int u,int fa,int v,int id,int www){
	//vis[u]=1;
	if(u==v){
		minn=min(minn,www+ww[u][id]);
		return ;
	}
	for(auto ed:e[u]){
		
		int tid=ed.id;
		int to=ed.v;
		if(fa==to)continue;
		if(vis[to])continue;
		vis[to]=1;
		//if(to==2)cout<<u<<' '<<id<<'\n';
		if(id==0 || tid==id){
			if(!id)www+=ww[u][tid];
			//pre[v]=u;
			//cout<<u<<"->"<<to<<" "<<www<<'\n';
			dfs(to,u,v,tid,www);
			if(!id)www-=ww[u][tid];
		}else{
			
			www+=ww[u][id];
			www+=ww[u][tid];
			//cout<<u<<"->"<<to<<" "<<www<<'\n';
			dfs(to,u,v,tid,www);
			www-=ww[u][id];
			www-=ww[u][tid];
		}
		vis[to]=0;
	}
	return ; 
}
signed main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int u,t;
		int v,tj;
		cin>>u>>t;
		for(int j=2;j<=k;j++){
			cin>>v>>tj;
			e[u].push_back({v,i});
			e[v].push_back({u,i});
			ww[u][i]=t;
			u=v,t=tj;
			if(j==k)ww[u][i]=t;
		}
		
	}
	
	for(int i=1;i<=q;i++){
		int st,en;
		cin>>st>>en;
		for(int i=1;i<=m;i++)vis[i]=0;
		vis[st]=1;
		dfs(st,0,en,0,0);
		cout<<w[st]+w[en]+minn<<'\n';
	}
	
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*//*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
