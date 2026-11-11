#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[600007],b[507][600007],k[507],x,y,ans,lp,pp,tt;
long long dis[600007];
struct node{
	int p,t,s;
};
vector<node> g[600007];
void dfs(long long u){
	if(u==y){
		return ;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].p;
		if(v!=0&&v<=m&&dis[u]<dis[v]){
			dis[v]=dis[u];
			dfs(v);
		} 
		else {
			if(dis[u]+g[u][i].t<dis[v]){
				dis[v]=dis[u]+g[u][i].t;
				dfs(v);
			}
		}	
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//Oct31==Dec25?
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>pp>>tt;
			if(i==1) fp=pp;
			if(i!=1){
				g[lp].push_back({pp,0});
				g[pp].push_back({fp,tt});
			}
			lp=pp;
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=m+1;i<=m+n;i++) dis[i]=1e18;
		dis[x]=0;
		dfs(x);
		cout<<dis[y]<<endl;
	}
	return 0;
}
