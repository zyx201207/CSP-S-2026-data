#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
int c,n,m,d,q;
ll w[M],dis[N][N];
struct edge{
	int v;
	ll w;
};
vector<edge>vec[M];
void add(int u,int v,ll w){
	dis[u][v]=dis[v][u]=min(dis[u][v],w);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		int len=vec[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				add(vec[i][j].v,vec[i][k].v,vec[i][j].w+vec[i][k].w);
			}
		}
	}
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=LLONG_MAX;
		for(edge s:vec[x]){
			for(edge t:vec[y]){
				if(dis[s.v][t.v]!=0x3f3f3f3f3f3f3f3f) ans=min(ans,dis[s.v][t.v]+s.w+t.w+w[x]+w[y]);
			}
		}
		cout<<ans<<endl;
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
