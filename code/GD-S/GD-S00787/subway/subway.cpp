#include<bits/stdc++.h>
using namespace std;
int C,m,n,w[1001000],fa[1001000],f[1001000][50],dep[1001000];
long long d,q,a[1001000],sum[1001000][50];
vector<int>edges[1001000];
map<int,int>b[1001000];
inline void solve(int x){
	for(auto y:edges[x])if(fa[y]==0)fa[y]=x,dep[y]=dep[x]+1,solve(y);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			edges[a].push_back(m+i),b[a][m+i]=t,edges[m+i].push_back(a),b[m+i][a]=t;
		}
	}
	dep[0]=0,fa[1]=-1,dep[1]=1,solve(1),fa[1]=0;
	for(int i=1;i<=n+m;i++)f[i][0]=fa[i],sum[i][0]=b[fa[i]][i];
	for(int i=1;i<=30;i++)
		for(int j=1;j<=n+m;j++){
			f[j][i]=f[f[j][i-1]][i-1];
			sum[j][i]=sum[f[j][i-1]][i-1]+sum[j][i-1];
		}
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=w[u]+w[v];
		if(dep[u]<dep[v])swap(u,v);
		for(int i=30;i>=0;i--)if(dep[f[u][i]]>=dep[v])ans+=sum[u][i],u=f[u][i];
		for(int i=30;i>=0;i--)if(f[u][i]!=f[v][i])ans+=sum[u][i],ans+=sum[v][i],u=f[u][i],v=f[v][i];
		if(u!=v)ans+=sum[u][0],ans+=sum[v][0],u=f[u][0],v=f[v][0];
		printf("%lld\n",ans);
	}
}
