#include<bits/stdc++.h>
#define ll long long
#define rep(i,X,Y) for(int i=(X);i<=(Y);i++)
#define per(i,X,Y) for(int i=(X);i>=(Y);i--)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

constexpr int N=510,M=5e5+10;

int taskc,n,m,d,q;

int wt[M];
vector<pii> g[M];

ll f[N][N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>taskc>>n>>m>>d>>q;
	rep(i,1,m) cin>>wt[i];
	rep(i,1,n) {
		int k; cin>>k;
		rep(j,1,k) {
			int a,t;
			cin>>a>>t;
			g[a].emplace_back(i,t);
		}
	}
	memset(f,0x3f,sizeof(f));
	rep(i,1,n) f[i][i]=0;
	rep(i,1,m) {
		for(auto it:g[i]) {
			int v=it.fi,w=it.se;
			for(auto it2:g[i]) {
				int v2=it2.fi,w2=it2.se;
				if(v!=v2) f[v][v2]=min(f[v][v2],(ll)w+w2);
			}
		}
	}
	rep(k,1,n) {
		rep(i,1,n) {
			rep(j,1,n) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--) {
		int x,y; cin>>x>>y;
		ll ans=1e18;
		for(auto ix:g[x]) {
			for(auto iy:g[y]) {
				int vx=ix.fi,wx=ix.se,vy=iy.fi,wy=iy.se;
				ans=min(ans,f[vx][vy]+wx+wy);
			}
		}
		cout<<ans+wt[x]+wt[y]<<'\n';
	}
	return 0;
} 
