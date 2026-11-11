#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fi first
#define se second
#define pii pair<int,int>
#define mkp make_pair
#define pb push_back
#define vi vector<int>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
#define vsz(x) (int)x.size()
#define ll long long

bool MemoryST;

const int N=5e5+10;
const int M=510;
const int inf=1e15+10;

vector<pii> e[N];
int m,n,d,q;
int ds[M][M],w[N];

void Mainsolve() {
	cin>>m>>m>>n>>d>>q;
	rep(i,1,n) cin>>w[i];
	rep(i,1,m) {
		int k;cin>>k;
		rep(p,1,k) {
			int u,w;cin>>u>>w; e[u].pb(mkp(i,w));
		} 
	}
	rep(i,1,m)
		rep(j,1,m)
			ds[i][j]=inf;
	rep(i,1,m)
		ds[i][i]=0; 
	rep(i,1,n) {
		for(auto p1:e[i]) for(auto p2:e[i]) {
			if(p1.fi!=p2.fi)
				ds[p1.fi][p2.fi]=min(ds[p1.fi][p2.fi],p1.se+p2.se);
		}
	}
	rep(k,1,m) rep(i,1,m) rep(j,1,m)
		ds[i][j]=min(ds[i][k]+ds[k][j],ds[i][j]);
	while(q--) {
		int u,v;cin>>u>>v;
		int ans=inf;
		for(auto p1:e[u])
			for(auto p2:e[v]) {
				ans=min(ans,ds[p1.fi][p2.fi]+p1.se+p2.se);
			}
		cout<<ans+w[u]+w[v]<<"\n"; 
	}
}

bool MemoryED;
signed main() {
//	system("fc subway.out subway7.ans"); exit(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cerr<<fixed<<setprecision(6)<<(&MemoryST-&MemoryED)/1024.0/1024.0<<"MB\n";
	
	int T=1; //cin>>T;
	while(T--) Mainsolve();
	
	cerr<<"\n"<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
