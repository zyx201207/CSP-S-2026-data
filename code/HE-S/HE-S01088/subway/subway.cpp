#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N=5e5+5;
int c,n,m,d,q,k;
ll w[N];
vector<pair<int,ll> >node[N];
ll dis[505][505];
ll solve(int u,int v){
	ll minn=1e18+214;
	for(auto au:node[u]){
		for(auto av:node[v]){
			minn=min(dis[au.fi][av.fi]+au.se+av.se,minn);
		}
	}
	return minn;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1,x,v;j<=k;j++){
			cin>>x>>v;
			node[x].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++){
		if(node[i].size()>=2){
			for(int j=0;j<node[i].size();j++){
				for(int k=0;k<node[i].size();k++){
					dis[node[i][j].fi][node[i][k].fi]=min(dis[node[i][j].fi][node[i][k].fi],node[i][j].se+node[i][k].se); 
				}
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||k==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		cout<<solve(u,v)+w[u]+w[v]<<'\n';
	}
	return 0;
}


