#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=510,M=5e5+10,D=20;
const ll inf=1e18;

template<class U,class V>
void gtmin(U &u,const V &v){if(v<u)u=v;}

int w[M],d[M],g[M][D],t[M][D];
ll f[N][N];
int main(){
//	freopen("subway6.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _c,n,m,_d,q;
	cin>>_c>>n>>m>>_d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1,k;i<=n;++i){
		cin>>k;
		for(int u,_t;k--;)
			cin>>u>>_t,g[u][++d[u]]=i,t[u][d[u]]=_t;
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=d[i];++j)
			for(int k=1;k<j;++k)
				gtmin(f[g[i][j]][g[i][k]],t[i][j]+t[i][k]);
	for(int i=1;i<=n;++i){
		f[i][i]=0;
		for(int j=1;j<=n;++j)
			gtmin(f[i][j],f[j][i]);
	}
//	for(int i=1;i<=n;++i)
//		for(int j=1;j<=n;++j)
//			cout<<setw(2)<<(f[i][j]==0x3f3f3f3f3f3f3f3f?-1:f[i][j])<<" \n"[j==n];
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				gtmin(f[i][j],f[i][k]+f[k][j]);
	for(int u,v;q--;){
		cin>>u>>v;
		ll ans=inf;
		for(int i=1;i<=d[u];++i)
			for(int j=1;j<=d[v];++j)
				gtmin(ans,t[u][i]+t[v][j]+f[g[u][i]][g[v][j]]);
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
