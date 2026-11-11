#include<bits/stdc++.h>
#define ll long long
#define db double
#define bint __int128
#define pii pair<int,ll>
#define fi first
#define se second
#define mkp make_pair
#define gc getchar
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
int ret(); bool vst;
const int N=505,M=5e5+5,mod=998244353;
const ll inf=1e18;
int c,n,m,d,q;
ll dis[N][N],ind[M];
vector<pii> to[M];
vector<pii> e[N];
void check(){
	for(int i=1;i<=m;i++)if(to[i].size()>d)assert(0);
}
void build(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(auto [v,t]:e[i])
			for(auto [w,_t]:to[v])
				chkmin(dis[i][w],t+_t);
	}
	// floyd
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			chkmin(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
}
ll query(int s,int t){
	ll res=inf,ext=ind[s]+ind[t];
	for(auto [sv,ts]:to[s])
		for(auto [tv,tt]:to[t])
			chkmin(res,ts+tt+dis[sv][tv]);
	return res+ext;
}
void sol(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ind[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		while(k--){
			int v;ll t;
			cin>>v>>t;
			e[i].emplace_back(v,t);
			to[v].emplace_back(i,t);
		}
	}
	build();
	while(q--){
		int x,y; cin>>x>>y;
		cout<<query(x,y)<<endl;
	}
}
bool ved; int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	sol();
	return ret();
}
int ret(){cerr<<"Space used: "<<abs((&vst)-(&ved))/1024.0/1024.0<<" MB."<<endl; return 0;}
//  Oct31==Dec25?
