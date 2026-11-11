#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=6e5+10,maxn=520;
inline int read(){
	int k=0,c=getchar_unlocked(),f=1;
	for(;!isdigit(c);c=getchar_unlocked())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar_unlocked())k=k*10+(c^48);
	return k*f;
}
int T,D,n,m,q,a[maxm],d[maxn][maxn];
struct edge{
	int v,w;
};
vector<edge>g[maxm];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	T=read(),n=read(),m=read(),D=read(),q=read();
	for(int i=1;i<=m;i++)a[i]=read();
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int u=read(),w=read();
			g[u].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)for(auto u:g[i])for(auto v:g[i])if(u.v!=v.v)d[u.v][v.v]=min(d[u.v][v.v],u.w+v.w),d[v.v][u.v]=min(d[v.v][u.v],u.w+v.w);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		int x=read(),y=read();
		int ans=1e18;
		for(auto u:g[x])for(auto v:g[y])ans=min(ans,v.w+u.w+d[u.v][v.v]);
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}
