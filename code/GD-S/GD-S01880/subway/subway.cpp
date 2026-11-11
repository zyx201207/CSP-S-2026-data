#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+100,N=510;
const ll inf=1e18;
int c,n,m,d,q;
ll mus[M];
ll dis[N][N];
vector<pair<int,ll> > e[M];
vector<pair<int,ll> > s[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>mus[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,w,v;j<=k;j++){
			cin>>v>>w;
			e[v].push_back({i,w});
			s[i].push_back({v,w});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int u=1,v;u<=n;u++){
		ll w;
		for(pair<int,ll> i:s[u]){
			for(pair<int,ll> tmp:e[i.first]){
				v=tmp.first,w=tmp.second+i.second;
				dis[u][v]=min(dis[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	while(q--){
		int u,v;
		ll ans=inf,sum=0;
		cin>>u>>v;
		for(pair<int,ll> i:e[u])
			for(pair<int,ll> j:e[v]){
				sum=i.second+j.second+dis[i.first][j.first];
				ans=min(ans,sum);
			}
		ans+=mus[u]+mus[v];
		cout<<ans<<'\n';
	}
	return 0;
}

