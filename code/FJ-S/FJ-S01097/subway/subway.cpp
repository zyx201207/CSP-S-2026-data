#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PIL pair<int,ll>
const int N=505;
const int M=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
ll w[M],dis[N][N];
vector<PIL >to[M];
void floyd(){
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int u=1;u<n;++u)
		for(int v=u+1;v<=n;++v)dis[u][v]=dis[v][u]=INF;
	for(int u=1;u<=n;++u)dis[u][u]=0;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a;
			ll t;
			cin>>a>>t;
			to[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;++i){
		for(PIL u:to[i])
			for(PIL v:to[i]){
				int t1=u.first,t2=v.first;
				ll d1=u.second,d2=v.second;
				if(t1==t2)continue;
				dis[t1][t2]=min(dis[t1][t2],d1+d2);
			}
	}
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(PIL u:to[x])
			for(PIL v:to[y]){
				int t1=u.first,t2=v.first;
				ll d1=u.second,d2=v.second;
				ans=min(ans,dis[t1][t2]+d1+d2);
			}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
