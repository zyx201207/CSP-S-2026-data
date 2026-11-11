#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <assert.h>
#define fin(f) freopen(f,"r",stdin)
#define fout(f) freopen(f,"w",stdout)
#define fo(i,l,r) for(int i=(l);i<=(r);i++)
#define of(i,r,l) for(int i=(r);i>=(l);i--)
#define debug cerr<<"["<<__LINE__<<"] "
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=5e5;
const int M=505;
ll f[M][M],w[N];
vector<pair<int,ll>>stos[N];
int main() {
	fin("subway.in");fout("subway.out");
	ios::sync_with_stdio(0);cin.tie(nullptr);
	int c,n,m,d,q;cin>>c>>m>>n>>d>>q;
	fo(i,1,n) cin>>w[i];
	fo(i,1,m) {
		int l;cin>>l;
		fo(j,1,l) {
			int a;ll t;cin>>a>>t;
			stos[a].pb(mp(i,t));
		}
	}
	fo(i,1,m) fo(j,1,m) f[i][j]=INF;
	fo(i,1,m) f[i][i]=0;
	fo(i,1,n)
		for(pair<int,ll> x:stos[i])
			for(pair<int,ll> y:stos[i]) {
				if(x.fi==y.fi) continue;
				f[x.fi][y.fi]=min(f[x.fi][y.fi],x.se+y.se);
			}
	fo(k,1,m) fo(i,1,m) fo(j,1,m)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	fo(i,1,q) {
		int x,y;cin>>x>>y;
		ll ans=INF;
		for(pair<int,ll> p:stos[x])
			for(pair<int,ll> q:stos[y])
				ans=min(ans,f[p.fi][q.fi]+p.se+q.se);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}