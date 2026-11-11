#include<bits/stdc++.h>
using namespace std;using ll=long long;using ull=unsigned long long;

constexpr int N=5e5+9,M=5e2+9;
constexpr ll inf=0x3f3f3f3f3f3f3f3f;
int qc,n,m,qd,qq;
ll iow[N]; //in - and - out time
vector<pair<ll,ll>> sv[N]; //station - vector [line id, time]
ll dis[M][M];
vector<pair<ll,ll>> lmt[M];
int cnt[N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<M;i++) dis[i][i]=0;
	cin.tie(0)->sync_with_stdio(0);
	cin>>qc>>n>>m>>qd>>qq;
	for(int i=1;i<=m;i++) cin>>iow[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		lmt[i].reserve(k+9);
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			lmt[i].emplace_back(x,y);
			cnt[x]++;
		}
	}
	for(int i=1;i<=m;i++) sv[i].reserve(cnt[i]+2);
	for(int i=1;i<=n;i++){
		for(int j=0;j<lmt[i].size();j++){
			int x=lmt[i][j].first,y=lmt[i][j].second;
			sv[x].emplace_back(i,y);
		}
	}
	for(int p=1;p<=m;p++){
		int l=sv[p].size();
		for(int i=1;i<l;i++){ //here - station id
			int u=sv[p][i].first;
			ll pk=sv[p][i].second;
			for(int j=0;j<i;j++){
				ll k=pk+sv[p][j].second;
				int v=sv[p][j].first;
				dis[u][v]=min(dis[u][v],k);
			}
		}
	}
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			dis[u][v]=min(dis[u][v],dis[v][u]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int k=1,u,v;k<=qq;k++){
		cin>>u>>v;
		ll ans=inf; //iow not included
		for(int i=0;i<sv[u].size();i++){ //begin with line i
			for(int j=0;j<sv[v].size();j++){ //end with line j
				ans=min(ans,sv[u][i].second+dis[sv[u][i].first][sv[v][j].first]+sv[v][j].second);
			}
		}
		cout<<ans+iow[u]+iow[v]<<'\n';
	}
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
