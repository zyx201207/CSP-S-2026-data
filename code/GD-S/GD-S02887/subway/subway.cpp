#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=(m);++i)
#define rev(i,n,m) for(int i(n);i>=(m);--i)
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int to[M][25];
ll f[N][N],w[M][25],a[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	rep(i,1,m) cin>>a[i];
	rep(i,1,n){
		int k,v,t;
		cin>>k;
		rep(j,1,k){
			cin>>v>>t;
			++to[v][0];
			to[v][to[v][0]]=i;
			w[v][to[v][0]]=t;
		}
	}
	memset(f,0x3f,sizeof(f));
	rep(i,1,m){
		rep(j,1,to[i][0]){
			rep(k,j+1,to[i][0]){
				int u=to[i][j],v=to[i][k];
				f[u][v]=min(f[u][v],w[i][j]+w[i][k]);
				f[v][u]=f[u][v];
			}
		}
	}
	rep(i,1,n) f[i][i]=0;
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(Q--){
		int u,v;
		cin>>u>>v;
		ll ans=0x3f3f3f3f3f3f3f3f;
		rep(i,1,to[u][0]){
			rep(j,1,to[v][0]){
				ans=min(ans,f[to[u][i]][to[v][j]]+w[u][i]+w[v][j]);
			}
		}
		ans+=a[u]+a[v];
		cout<<ans<<"\n";
	}
	return 0;
}
