#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e2+10;
ll c,n,m,d,q,x,y;
ll w[N],k;
struct station{
	ll a,t;
};
vector<station>ac[N];
ll g[N][N];
ll f[N][N][N];
int main(){
	memset(g,0x3f,sizeof g);
	memset(f,0x3f,sizeof f);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>x>>y;
			ac[x].push_back({i,y});
		}
	}
	for(ll i=1;i<=m;i++)
		for(ll u=0;u<ll(ac[i].size());u++)
			for(ll v=u+1;v<ll(ac[i].size());v++){
				g[ac[i][u].a][ac[i][v].a]=min(g[ac[i][u].a][ac[i][v].a],ac[i][u].t+ac[i][v].t);
				g[ac[i][v].a][ac[i][u].a]=min(g[ac[i][v].a][ac[i][u].a],ac[i][v].t+ac[i][u].t);
			}
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++){
			f[i][i][k]=0;
			for(ll j=i+1;j<=n;j++)
				f[i][j][k]=f[j][i][k]=min(min(f[i][j][k-1],f[i][k][k-1]+f[j][k][k-1]),g[i][j]);
		}
	while(q--){
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto u:ac[x])
			for(auto v:ac[y]) ans=min(ans,f[u.a][v.a][n]+u.t+v.t);
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
