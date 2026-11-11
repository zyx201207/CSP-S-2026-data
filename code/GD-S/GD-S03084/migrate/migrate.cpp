#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN=2e6,INF=0x3f3f3f3f3f3f3f3f;
int n,d;
int x[MAXN+5],f[MAXN+5],g[MAXN+5];

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>x[i];
	int ans=0;
	for(int u=1;u<=n;++u){
		f[u]=0,g[u]=1;
		for(int i=u+1;i<=n;++i){
			f[i]=INF,g[i]=0;
			for(int j=i-1;j>=u;--j){
				if(x[i]-x[j]>d) break;
				if(f[j]+1<f[i]) f[i]=f[j]+1,g[i]=g[j];
				else if(f[j]+1==f[i]) g[i]+=g[j];
			}
		}
		for(int v=u+1;v<=n;++v) if(g[v]==2) ++ans;
	}
	cout<<ans<<"\n";
}

signed main(){
	freopen("migrate3.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	int c,t; cin>>c>>t;
	while(t--) solve();
	return 0;
}
