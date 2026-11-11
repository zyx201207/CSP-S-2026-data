#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
const int N=505,M=5e5+5,K=25;
const ll inf=1e17;
int c,n,m,d,q,len,sp,st;
int a[M],tot[M],p[M][K],t[M][K];
ll w[N][N];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		cin>>len;
		for(int j=1;j<=len;j++) {
			cin>>sp>>st;
			tot[sp]++;
			t[sp][tot[sp]]=st;
			p[sp][tot[sp]]=i;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			w[i][j]=inf;
		}
		w[i][i]=0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=tot[i];j++) {
			int u=p[i][j];
			for(int k=1;k<=tot[i];k++) {
				int v=p[i][k];
				w[v][u]=min(w[v][u],1ll*t[i][j]+t[i][k]);
				w[u][v]=min(w[u][v],1ll*t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				w[j][i]=w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int x,y;
		ll ans=inf;
		cin>>x>>y;
		for(int j=1;j<=tot[x];j++) {
			for(int k=1;k<=tot[y];k++) {
				ans=min(ans,1ll*t[x][j]+t[y][k]+w[p[x][j]][p[y][k]]);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
}
