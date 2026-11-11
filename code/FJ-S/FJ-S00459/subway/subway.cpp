#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
const int N=5e5+5,M=505;
int c,n,m,d,q,cnt,head[N],to[N],nex[N];
ll a[N],dis[M][M],e[M][M],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			ll t;
			cin>>x>>t;
			nex[++cnt]=head[x];
			head[x]=cnt;
			to[cnt]=i+m;
			w[cnt]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) e[i][j]=dis[i][j]=INF;
		e[i][i]=dis[i][i]=0LL;
	}
	for(int i=1;i<=m;i++){
		for(int j=head[i];j;j=nex[j]){
			int r=to[j];
			for(int k=nex[j];k;k=nex[k]){
				int nr=to[k];
				e[r-m][nr-m]=min(e[r-m][nr-m],w[j]+w[k]);
				e[nr-m][r-m]=e[r-m][nr-m];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=e[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++) dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(int j=head[x];j;j=nex[j]){
			for(int k=head[y];k;k=nex[k]) ans=min(ans,w[j]+w[k]+dis[to[j]-m][to[k]-m]+a[x]+a[y]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
