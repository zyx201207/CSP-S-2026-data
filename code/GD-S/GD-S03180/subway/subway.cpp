#include<bits/stdc++.h>
using namespace std;
/*
每两个地铁站之间建边，跑floyd
每两个点之间就d^2枚举进入的线 
*/
const int M=5e5+5,N=505;
int c,n,m,d,q;
int w[M],s[N][M];
long long f[N][N];
vector<int> r[N],h[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		int k,a,t;
		cin>>k;
		while(k--){
			cin>>a>>t;
			s[i][a]=t;
			r[i].push_back(a);
			h[a].push_back(i);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i)
		f[i][i]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			for(int u:r[i])
				if(s[i][u]&&s[j][u])
					f[i][j]=min(f[i][j],(long long)s[i][u]+s[j][u]);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		long long ans=1e18;
		cin>>x>>y;
		for(int u:h[x])
			for(int v:h[y])
				ans=min(ans,(long long)s[u][x]+s[v][y]+f[max(u,v)][min(u,v)]);
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
} 
