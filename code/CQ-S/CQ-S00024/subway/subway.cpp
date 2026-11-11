#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10,inf=1e18;
int c,n,m,d,q,w[M],K,f[N][N],a,t,x,y;
struct node{
	int a,t;
};
vector<node> ps[M],vc[M];
inline void wk(int u,int v,int w){
	f[u][v]=min(f[u][v],w),f[v][u]=min(f[v][u],w);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>K;
		for(int j=1;j<=K;j++){
			cin>>a>>t;
			ps[i].push_back({a,t}),vc[a].push_back({i,t});
		}
	}
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=n;i++)
		for(auto &j:ps[i])
			for(auto &k:vc[j.a])
				wk(i,k.a,j.t+k.t);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		cin>>x>>y;
		int ans=1e18;
		for(auto &i:vc[x])
			for(auto &j:vc[y])
				ans=min(ans,w[x]+w[y]+f[i.a][j.a]+i.t+j.t);
		cout<<ans<<"\n"; 
	}
	return 0;
}
