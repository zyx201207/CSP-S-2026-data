#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long 
#define pii pair<int,int>
#define pil pair<int,ll>
#define vi vector<int>
#define vpi vector<pii>
#define vpl vector<pil>
#define fi first
#define se second
int c,n,m,d,q;
int w[500010];
ll dis[510][510];
const ll inf=1e13;
vpi g[500010];
void work(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({m+i,t});
//			g[m+i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				dis[g[i][j].fi-m][g[i][k].fi-m]=min(dis[g[i][j].fi-m][g[i][k].fi-m],(ll)g[i][j].se+g[i][k].se);
				dis[g[i][k].fi-m][g[i][j].fi-m]=min(dis[g[i][k].fi-m][g[i][j].fi-m],(ll)g[i][j].se+g[i][k].se);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<",";
//		}
//		cout<<"\n";
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(j==i||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<",";
//		}
//		cout<<"\n";
//	}
	//md^2+n^3/n^2logn dis between routes
	//ask x y
	//qd^2
	//d20?
	//n500?
	//only cal walk?
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf,bs=w[x]+w[y];
		for(pii px:g[x]){
			int u=px.fi-m,dx=px.se;
			for(pii py:g[y]){
				int v=py.fi-m,dy=py.se;
				ans=min(ans,dis[u][v]+dx+dy);
			}
		}
		cout<<bs+ans<<"\n";
	}
	//O(md^2+n^3+qd^2)
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--){
		work();	
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
