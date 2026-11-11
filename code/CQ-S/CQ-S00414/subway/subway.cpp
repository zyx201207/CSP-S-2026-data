#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,w;	
};
int c,n,m,d,q,w[500005],k[500005],vis[500005],dis[500005],l; 
vector<node> a[505];
vector<node> E[500005];
void dfs(int x,int cnt,int fa){
	
dis[x]=min(dis[x],cnt);
vis[x]=1;
	for(auto o:E[x]){
		int flag=1;
		for(auto v1:a[o.v]){
			if(v1.v==x){
				flag=0;
				continue;
			}
			if(flag) continue;
			dfs(v1.v,cnt+v1.w+o.w,x);
		}
	}
}
void dfs2(int x,int fa){
	for(auto o:E[x]){
		if(o.v!=fa){
			dis[o.v]=min(dis[o.v],dis[x]+o.w);
			dfs2(o.v,x);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c<=6){
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int vv,ww;
				cin>>vv>>ww;
				a[i].push_back({vv,ww});
				E[vv].push_back({i,ww}); 
			}
		}
		while(q--){
			int r;
			cin>>l>>r;
			for(int i=1;i<=m;i++){
				dis[i]=1e18;
				vis[i]=0;
			}
			dfs(l,0,-1);
			cout<<dis[r]+w[l]+w[r]<<"\n";
		}	
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>k[i];
			if(k[i]==1) continue;
			int u,v,t1,t2;
			cin>>u>>t1>>v>>t2;
			E[u].push_back({v,t1+t2});
			E[v].push_back({u,t1+t2});
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			for(int i=1;i<=m;i++){
				dis[i]=1e18;
			}
			dis[l]=0;
			dfs2(l,-1);
			cout<<dis[r]+w[l]+w[r]<<"\n";
		}
	}
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
