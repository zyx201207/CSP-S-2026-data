#include<iostream>
#include<vector>
#include<cstdio>
#include<cctype>
#include<cstdio>
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=510,M=5e5+10,D=30;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct edge{
	ll v,w;
};
vector<edge> stn[M];
ll w[M];
ll dis[N][N];
ll n,m,d,q;
void solve(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=inf;
		}
	ll u,v,w,ww;
	for(int i=1;i<=m;i++){
		for(edge it:stn[i]){
			u=it.v,w=it.w;
			for(edge itt:stn[i]){
				v=itt.v,ww=itt.w;
				if(u==v) continue;
				dis[u][v]=dis[v][u]=min(dis[u][v],w+ww);
			}
		}
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	ll k;
	for(int i=1,v,w;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>v>>w;
			stn[v].push_back({i,w});
		}
	}
	solve();
	floyd();
	ll u,v;
	while(q--){
		cin>>u>>v;
		ll ans=inf;
		for(edge it:stn[u])
			for(edge itt:stn[v])
				ans=min(ans,it.w+itt.w+dis[it.v][itt.v]);
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
