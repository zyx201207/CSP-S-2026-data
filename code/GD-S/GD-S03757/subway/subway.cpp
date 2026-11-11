#include <bits/stdc++.h>
using namespace std;

namespace tymxz{
	const int N=507,M=5e5+7;
	typedef long long ll;
	const ll inf=0x3f3f3f3f3f3f3f3f;
	int c,n,m,d,q;
	int w[M];
	vector<pair<int,int> > g[M];
	ll f[N][N];
	inline void chmin(ll &a,ll b){
		if(b<a) a=b;
	}
	void subt(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1,a,t;j<=k;j++){
				cin>>a>>t;
				g[a].push_back(make_pair(i,t));
			}
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=inf;
		for(int i=1;i<=n;i++) f[i][i]=0;
		for(int i=1;i<=m;i++){
			for(auto x:g[i]){
				for(auto y:g[i]){
					chmin(f[x.first][y.first],x.second+y.second);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					chmin(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(int i=1,x,y;i<=q;i++){
			cin>>x>>y;
			ll ans=inf;
			for(auto i:g[x]){
				for(auto j:g[y]){
					chmin(ans,f[i.first][j.first]+i.second+j.second);
				}
			}
			ans+=w[x]+w[y];
			cout<<ans<<endl;
		}
	}
}
signed main(){
	freopen("subway.in" ,"r",stdin );
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	tymxz::subt();
	return 0;	
} 
