#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define F(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define dF(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
#define pb push_back
#define fi first
#define se second
#define mkp make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define bll __int128
#define infll 1000000000000000000ll
using namespace std;
void fre(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
}
bool ST;
template<typename T>inline void chkmax(T&x,const T&y){ x=max(x,y); }
template<typename T>inline void chkmin(T&x,const T&y){ x=min(x,y); }
const int maxn=500005,NR=505;
int n,m,K,Q;
ll w[maxn];
vector<pii>g[maxn];
ll dis[NR][NR];
void solve(int cid){
	cin>>n>>m>>K>>Q;
	F(i,1,m)cin>>w[i];
	F(i,1,n){
		int len;cin>>len;
		while(len--){
			int u,val;cin>>u>>val;
			g[u].push_back(mkp(i,val));
		}
	}
	F(i,1,n)F(j,1,n)dis[i][j]=infll;
	F(u,1,m)F(i,0,SZ(g[u])-1)F(j,i+1,SZ(g[u])-1){
		int x=g[u][i].fi,y=g[u][j].fi;
		ll val=g[u][i].se+g[u][j].se;
		chkmin(dis[x][y],val),chkmin(dis[y][x],val);
	}
	F(k,1,n)F(i,1,n)F(j,1,n)if(i!=j&&j!=k&&k!=i)chkmin(dis[i][j],dis[i][k]+dis[k][j]);
	while(Q--){
		int x,y;cin>>x>>y;
		ll ans=infll;
		F(i,0,SZ(g[x])-1)F(j,0,SZ(g[y])-1){
			int u=g[x][i].fi,v=g[y][j].fi;
			ll tot=g[x][i].se+g[y][j].se;
			if(u!=v)tot+=dis[u][v];
			chkmin(ans,tot);
		}
		ans+=w[x]+w[y],cout<<ans<<'\n';
	}
}
bool ED;
signed main(){
	fre(),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int allT=1,testid;cin>>testid;
	F(_,1,allT)solve(_);
	cerr<<"time used: "<<((double)clock()/CLOCKS_PER_SEC)<<endl;
	cerr<<"memory used: "<<(abs(&ST-&ED)/1024.0/1024.0)<<"MiB"<<endl;
}
// g++ b.cpp -o a -std=c++14 -O2