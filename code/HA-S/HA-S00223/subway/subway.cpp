#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (ll)(1e18)

const int N=5e5+10;

int ce,n,m,d,q;
int a[N];

inline int read(){
	int t=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9') f=(c=='-')?(-1):(f),c=getchar();
	while(c>='0'&&c<='9') t=(t<<3)+(t<<1)+(c^48),c=getchar();
	return t*f;
}

#define pr pair<int,int>

vector<pr> g[N];

const int M=510;

ll dis[M][M];

void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ce=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		int cnt=read();
		for(int j=1;j<=cnt;j++){
			int u=read(),w=read();
			g[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int j1=j+1;j1<g[i].size();j1++){
				int u=g[i][j].first,wu=g[i][j].second;
				int v=g[i][j1].first,wv=g[i][j1].second;
				dis[u][v]=dis[v][u]=wu+wv;
			}
		}
	}
	Floyd();
	while(q--){
		int u=read(),v=read();
		ll ans=inf;
		for(int i=0;i<g[u].size();i++)
			for(int j=0;j<g[v].size();j++)
				ans=min(ans,g[u][i].second+g[v][j].second+dis[g[u][i].first][g[v][j].first]);
		ans+=a[u]+a[v];
		cout<<ans<<"\n";
	}
	return 0;
}
//15:04 done

