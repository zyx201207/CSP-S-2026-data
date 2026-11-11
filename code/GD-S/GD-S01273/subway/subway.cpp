#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define il inline
const ll P=998244353;
const int M=5e5+10, N=5e2+10;
ll qp(ll a,ll b=P-2){
	ll res=1;
	for(;b;b>>=1,a=(a*a)%P) if(b&1) res=res*a%P;
	return res;
}
// ------------------------------------------------- //
int test_id, n,m,d,q, k[M]; ll f[N][N]; int w[M], cnt[M];
vector<pair<int,int>> subways[M];
il void ckmin(ll &p,ll v){ p=(p>v?v:p); }
// ------------------------------------------------- //
il void solve(){
	cin>>test_id>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) f[i][j]=1e18;
		f[i][i]=0;
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int tmp=1;tmp<=k[i];++tmp){
			int node_id, go_time; cin>>node_id>>go_time;
			++cnt[node_id];
			subways[node_id].push_back({i, go_time});
		}
	} 
	for(int i=1;i<=m;++i){
		for(int lid_u=0;lid_u<cnt[i];++lid_u) for(int lid_v=lid_u+1;lid_v<cnt[i];++lid_v){
			int tl_u=subways[i][lid_u].fi, tl_v=subways[i][lid_v].fi;
			ll  tm_u=subways[i][lid_u].se, tm_v=subways[i][lid_v].se;
			ckmin(f[tl_u][tl_v],tm_u+tm_v);
			ckmin(f[tl_v][tl_u],tm_u+tm_v); 
		}
	}
	for(int mid=1;mid<=n;++mid) for(int i=1;i<=n;++i) if(f[i][mid]<1e18) for(int j=1;j<=n;++j)
		ckmin(f[i][j],f[i][mid]+f[mid][j]);
	while(q--){
		int st,ed; cin>>st>>ed;
		ll ans=1e18;
		for(int lid_u=0;lid_u<cnt[st];++lid_u) for(int lid_v=0;lid_v<cnt[ed];++lid_v){
			int tl_u=subways[st][lid_u].fi, tl_v=subways[ed][lid_v].fi;
			ll  tm_u=subways[st][lid_u].se, tm_v=subways[ed][lid_v].se;
//			cerr<<"[Query] now try line "<<tl_u<<" in "<<tl_v<<" out\n";
//			cerr<<"[Query] "<<st<<"->"<<ed<<" into="<<w[st]+w[ed]<<" inline="<<tm_u+tm_v<<" "<<" disinline="<<f[tl_u][tl_v]<<"\n";
			ckmin(ans,w[st]+w[ed]+tm_u+tm_v+f[tl_u][tl_v]); 
		}
		cout<<ans<<"\n";
	}
	return;
}
// ------------------------------------------------- //
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve(); 
	return 0;
}
