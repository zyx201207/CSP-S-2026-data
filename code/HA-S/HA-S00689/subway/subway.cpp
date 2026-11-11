#include<bits/stdc++.h>

using namespace std;
#define maxm 555555
#define maxn 505
#define ll long long
int c,n,m,d,q;
int w[maxm],k[maxn];
vector<pair<ll,ll> >e[maxm]; 
ll dis[maxn][maxn];

// 不能给个新一点的mingw吗? 

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof dis);
//	cerr<<"BOOM1\n";
	for(int i=1;i<=n;i++){
		cin>>k[i];
		dis[i][i] = 0;
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
//			cerr<<i<<' '<<a+n<<' '<<t;
			e[i].push_back({a+n,t});
			e[a+n].push_back({i,t});
		}
	}
//	cerr<<"BOOM2\n";
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
//		for(auto [j,t]:e[i]){
			ll rj = e[i][j].first,t=e[i][j].second;
			for(int rk=0;rk<e[rj].size();rk++){
//			for(auto [k,w]:e[rj])
				ll k = e[rj][rk].first,w=e[rj][rk].second; 
				dis[i][k]=min(dis[i][k],t+w);
			}
		}
	}
//	cerr<<"BOOM3\n";
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
		dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}	
		}
	}
//	cerr<<"BOOM4\n";
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=LONG_LONG_MAX;
		for(int i=0;i<e[x+n].size();i++){
			ll rx = e[x+n][i].first,t=e[x+n][i].second;
//		for(auto [rx,t]:e[x+n]){
			for(int j=0;j<e[y+n].size();j++){
				ll ry = e[y+n][j].first,rt=e[y+n][j].second;
//			for(auto [ry,rt]:e[y+n]){
				ans=min(ans,dis[rx][ry]+t+rt);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	
	return 0;
}
//-std=c++14 subway
