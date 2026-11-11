#include <bits/stdc++.h>
#define fo(i,l,r) for(int i(l); i<=(r); ++i)
#define fu(i,l,r) for(int i(l); i<(r); ++i)
#define fd(i,l,r) for(int i(l); i>=(r); --i)
#define File "subway"
#define pb push_back
#define il inline
#define sz(x) (int((x).size()))
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
const ll inf=1ll<<60;
int tid,n,m,d,q,a[M];
ll f[N][N];
vector<array<int,2>> e[M];
int main() {
	freopen(File".in","r",stdin);
	freopen(File".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>tid>>n>>m>>d>>q;
	fo(i,1,m) cin>>a[i];
	fo(i,1,n) {
		int k;
		cin>>k;
		fo(j,1,k) {
			int x,y;
			cin>>x>>y;
			e[x].pb({i,y});
		}
	}
	fo(i,1,n) fo(j,1,n) f[i][j]=inf;
	fo(i,1,n) f[i][i]=0;
	fo(i,1,m) for(auto [x0,y0] : e[i]) for(auto [x1,y1] : e[i]) if(x0!=x1) f[x0][x1]=min<ll>(f[x0][x1],y0+y1);
	fo(j,1,n) fo(i,1,n) fo(k,1,n) f[i][k]=min(f[i][k],f[i][j]+f[j][k]);
	fo(i,1,n) fo(j,1,n) fo(k,1,n) f[i][k]=min(f[i][k],f[i][j]+f[j][k]);
	fo(k,1,n) fo(i,1,n) fo(j,1,n) f[i][k]=min(f[i][k],f[i][j]+f[j][k]);
	fo(i,1,q) {
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(auto [x0,y0] : e[x])
			for(auto [x1,y1] : e[y])
				ans=min(ans,f[x0][x1]+y0+y1);
		ans+=a[x]+a[y];
		cout<<ans<<'\n';
	}
	return 0;
}