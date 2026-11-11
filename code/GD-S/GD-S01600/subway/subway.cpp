#include<bits/stdc++.h>
using namespace std;
#define i128 __int128
#define ull unsigned long long
#define int long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
const int mod=1;
template<typename T>inline void cmin(T&x,T y){x=(x<y?x:y);}
template<typename T>inline void cmax(T&x,T y){x=(x>y?x:y);}
template<typename T>inline int fplus(T x,T y){return x+y-(x+y>=mod?mod:0);}
template<typename T>inline void cplus(T&x,T y){x=fplus(x,y);}
template<typename T>inline int fminus(T x,T y){return x-y+(x-y<=0?mod:0);}
template<typename T>inline void cminus(T&x,T y){x=fminus(x,y);}
template<typename T>inline int qp(T x,T y){
	T ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ans;
}
const int inf=0x3f3f3f3f3f3f3f3f;
bool be;
int c,n,m,d,q,w[500005],k,x,y,dis[505][505];
vector<pii>v[500005];
void solve(){
	cin>>c>>n>>m>>d>>q;
	fo(i,1,m)cin>>w[i];
	fo(i,1,n){
		cin>>k;
		fo(j,1,k)cin>>x>>y,v[x].pb({i,y});
		fo(j,1,n)if(i^j)dis[i][j]=inf;
	}
	fo(i,1,m)fo(j,0,(int)v[i].size()-2)fo(k,j+1,(int)v[i].size()-1)
		cmin(dis[v[i][j].fi][v[i][k].fi],v[i][j].se+v[i][k].se),
		cmin(dis[v[i][k].fi][v[i][j].fi],v[i][j].se+v[i][k].se);
//		cout<<"! "<<i<<' '<<j<<' '<<k<<' '<<v[i][j].fi<<' '<<v[i][k].fi<<' '<<v[i][j].se+v[i][k].se<<'\n';
	fo(k,1,n)fo(i,1,n)fo(j,1,n)cmin(dis[i][j],dis[i][k]+dis[k][j]);
//	fo(i,1,n)fo(j,1,n)cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
	fo(_,1,q){
		cin>>x>>y;
		int ans=inf;
		for(pii j:v[x])for(pii k:v[y])cmin(ans,w[x]+w[y]+j.se+k.se+dis[j.fi][k.fi]);
		cout<<ans<<'\n';
	}
}
bool bg;
signed main(){
//	#ifndef QWERTIM
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
//	#endif
//	freopen("subway7.in","r",stdin),freopen("my.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)solve();
//	cerr<<'\n'<<abs((&be)-(&bg))/1048576.;
	return 0;
}
