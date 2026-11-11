#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
int c,n,m,d,Q;
ll ww[maxn];
int k[maxn];
struct edge{
	ll v,w;
};
vector<edge>a[505];
vector<edge>b[maxn];
ll dis[505][505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>ww[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		ll u,t;
		for(int j=1;j<=k[i];j++){
			cin>>u>>t;
			a[i].push_back({u,t});
			b[u].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(auto u:a[i]){
			for(auto v:b[u.v]){
				dis[i][v.v]=min(dis[i][v.v],u.w+v.w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int l,r;
	for(int i=1;i<=Q;i++){
		cin>>l>>r;
		ll ans=9e18;
		for(auto u:b[l]){
			for(auto v:b[r]){
				ans=min(ans,dis[u.v][v.v]+u.w+v.w);
			}
		}
		cout<<ans+ww[l]+ww[r]<<'\n';
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
